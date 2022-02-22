
#include "Level2.h"
#include "Level3.h"
USING_NS_CC;

    Scene* Level2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);


    // 'layer' is an autorelease object
    auto layer = Level2::create();
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene  ;
}






// on "init" you need to initialize your instance
bool Level2::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getVisibleSize();


// 3





    auto background = DrawNode::create();
    background->drawSolidRect(origin, winSize, Color4F(39, 245, 226, 0.5));
    this->addChild(background);

    int x= 25;
    for (int i = 0; i < 5; ++i) {
        x+=100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(x,225));//d fixe dans y
        this->addChild(carr);
        lista1.push_back(carr);
    }


    int y= 150;
    for (int i = 0; i < 3; ++i) {
        y+=100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(525,y));
        this->addChild(carr);
        lista2.push_back(carr);
    }

    for (int i = 0; i < 4; ++i) {
        x-=100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(x,450));
        this->addChild(carr);
        lista3.push_back(carr);
    }

    int xa=125;// le plus haut
    for (int i = 0; i < 4; ++i) {
        xa+=100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(xa,675));
        this->addChild(carr);
        lista4.push_back(carr);
    }
   int yab=425;
    for (int i = 0; i <3 ; ++i) {
        yab+=100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(125,yab));
        this->addChild(carr);
        lista5.push_back(carr);
    }

//BALL

    Ball = Sprite::create("ball2.png");
    Ball->setPosition(Vec2( 125, 225));
    this->addChild(Ball);
    Ball->setLocalZOrder(50);



    // Obstacle

    auto horiz1 = Sprite::create("Horizental.png");
    horiz1->setPosition(Point(325,750));
    this->addChild(horiz1,1);
    auto horiz2 = Sprite::create("Horizental.png");
    horiz2->setPosition(Point(325,150));
    this->addChild(horiz2);
    auto vert1 = Sprite::create("Vertical.png");
    vert1->setPosition(Point(50,575));
    this->addChild(vert1);
    auto vert2= Sprite::create("Vertical.png");
    vert2->setPosition(Point(50,350));
    this->addChild(vert2);
    auto vert3 = Sprite::create("Vertical.png");
    vert3->setPosition(Point(600,575));
    this->addChild(vert3);
    auto vert4= Sprite::create("Vertical.png");
    vert4->setPosition(Point(600,350));
    this->addChild(vert4);







    //Key Pressed

    auto eventListner = EventListenerKeyboard::create();
    eventListner->onKeyPressed=CC_CALLBACK_2(Level2::keyPressed, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListner,this);


    return true;
}



void Level2::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event ) {


    auto action1 = MoveTo::create(0.1, Vec2(525, Ball->getPositionY()));
    auto action2 = MoveTo::create(0.1,Vec2(Ball->getPositionX(), 450));
    auto action3 = MoveTo::create(0.1, Vec2(125, Ball->getPositionY()));
    auto action4 = MoveTo::create(0.1,Vec2(Ball->getPositionX(), 227 ));
    auto action5 = MoveTo::create(0.1,Vec2(Ball->getPositionX(), 675 ));
    auto action6 = MoveTo::create(0.1,Vec2(Ball->getPositionX(), 450 ));
    switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            Ball->runAction(action1);
            if(Ball->getPositionY()<300 )
                for (int i = 0; i < lista1.size(); ++i) {
                    DrawNode* drawNode = DrawNode::create();
                    drawNode->drawPoint(Vec2(lista1[i]->getPosition()), 100, Color4F::GRAY);
                    this->addChild(drawNode);
                }
            if (Ball->getPositionY()>500)
                for (int i = 0; i < lista4.size(); ++i) {
                    DrawNode* drawNode = DrawNode::create();

//
                    drawNode->drawPoint(Vec2(lista4[i]->getPosition()), 100, Color4F::GRAY);
                    this->addChild(drawNode);

                }

            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
            if(Ball->getPositionX()>150&& Ball->getPositionY()<500){
                Ball->runAction(action2);


            } else if(Ball->getPositionX()<150 && Ball->getPositionY()>240  ){
                Ball->runAction(action5);//675

            }
            if(Ball->getPositionX()>150)
                for (int i = 0; i < lista2.size(); ++i) {
                    DrawNode* drawNode = DrawNode::create();

//
                    drawNode->drawPoint(Vec2(lista2[i]->getPosition()), 100, Color4F::GRAY);
                    this->addChild(drawNode);
                } else

            if(Ball->getPositionY()>300)
                for (int i = 0; i < lista5.size(); ++i) {
                    DrawNode* drawNode = DrawNode::create();

//
                    drawNode->drawPoint(Vec2(lista5[i]->getPosition()), 100, Color4F::GRAY);
                    this->addChild(drawNode);
                }
            break;
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            Ball->runAction(action3);
            if( Ball->getPositionY()>300)
                for (int i = 0; i < lista3.size(); ++i) {
                    DrawNode* drawNode = DrawNode::create();

//
                    drawNode->drawPoint(Vec2(lista3[i]->getPosition()), 100, Color4F::GRAY);
                    this->addChild(drawNode);

                }



            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            if( Ball->getPositionX()>150 &&Ball->getPositionY()<470)
                Ball->runAction(action4
                ); else if(Ball->getPositionY()>250 &&Ball->getPositionX()<150)
                Ball->runAction(action6);

            break;

    }

    if (Ball->getPositionY() > 650 &&   (Ball->getPositionX()-525<50 || 525- Ball->getPositionX()<50 )  ) {

        Scene *pScene = Level3::createScene();
        TransitionPageTurn *crosssfade = TransitionPageTurn::create(0.3, pScene, true);
        Director::getInstance()->replaceScene(crosssfade);

    }
}




