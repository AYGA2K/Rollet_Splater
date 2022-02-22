

#include "Level4.h"
#include "Level5.h"

USING_NS_CC;

Scene* Level4::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();



    // 'layer' is an autorelease object
    auto layer = Level4::create();
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}






// on "init" you need to initialize your instance
bool Level4::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getVisibleSize();

    LayerColor *_bgColor = LayerColor::create(Color4B::GREEN);
    this->addChild(_bgColor );

//ball

    Ball = Sprite::create("ball2.png");
    Ball->setPosition(Vec2( 150, 250));
    this->addChild(Ball);
    Ball->setLocalZOrder(50);

    int y=150;
    for (int i = 0; i < 5; ++i) {
        y += 100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(150, y));
        this->addChild(carr);
        lista1.push_back(carr);

    }
    int x=150;
    for (int i = 0; i < 5; ++i) {
        x+= 100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(x, 650));
        this->addChild(carr);
        lista2.push_back(carr);
    }
    int ya=650;
    for (int i = 0; i < 4; ++i) {
        ya -= 100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(650, ya));
        this->addChild(carr);
        lista3.push_back(carr);

    }
    int xa=250;
    for (int i = 0; i < 4; ++i) {
        xa+= 100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(xa, 250));
        this->addChild(carr);
        lista4.push_back(carr);

    }
    int yb=250;
    for (int i = 0; i < 6; ++i) {
        yb+= 100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(350, yb));
        this->addChild(carr);
        lista5.push_back(carr);

    }
    int xb=350;
    for (int i = 0; i < 3; ++i) {
        xb+= 100;
        auto carr = Sprite::create("care2.png");
        carr->setPosition(Point(xb, 850));
        this->addChild(carr);
        lista6.push_back(carr);

    }






    //Key Pressed

    auto eventListner = EventListenerKeyboard::create();
    eventListner->onKeyPressed=CC_CALLBACK_2(Level4::keyPressed,this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListner,this);



    return true;
}


void Level4::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event ) {


    auto action1 = MoveTo::create(0.1, Vec2(Ball->getPositionX(), 650));
    auto action2 = MoveTo::create(0.1, Vec2(650, Ball->getPositionY()));
    auto action3 = MoveTo::create(0.1, Vec2(Ball->getPositionX(), 250));
    auto action4 = MoveTo::create(0.1, Vec2(350, Ball->getPositionY()));
    auto action5 = MoveTo::create(0.1, Vec2(Ball->getPositionX(), 450));
    auto action6 = MoveTo::create(0.1, Vec2(450, Ball->getPositionY()));
    switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:

            if (Ball->getPositionY() > 300)
                Ball->runAction(action2);
            if (Ball->getPositionY() > 650)
                for (int i = 0; i < lista6.size(); ++i) {
                    DrawNode *drawNode = DrawNode::create();
                    drawNode->drawPoint(Vec2(lista6[i]->getPosition()), 100, Color4F::MAGENTA );
                    this->addChild(drawNode);
                }

            if (Ball->getPositionX() > 300 && Ball->getPositionY() < 300  )
                Ball->runAction(action2);
            if (Ball->getPositionY()>500 && Ball->getPositionX()<400 ) {
                for (int i = 0; i < lista2.size(); ++i) {
                    DrawNode *drawNode = DrawNode::create();
                    drawNode->drawPoint(Vec2(lista2[i]->getPosition()), 100, Color4F::MAGENTA);
                    this->addChild(drawNode);
                }
            }
            break;

        case EventKeyboard::KeyCode::KEY_UP_ARROW:
            Ball->runAction(action1);
            for (int i = 0; i < lista1.size(); ++i) {
                DrawNode *drawNode = DrawNode::create();
                drawNode->drawPoint(Vec2(lista1[i]->getPosition()), 100, Color4F::MAGENTA);
                this->addChild(drawNode);
            }
            if (Ball->getPositionX() > 200 && Ball->getPositionX() < 550) {
                Ball->runAction(action5);
                for (int i = 0; i < lista5.size(); ++i) {
                    DrawNode *drawNode = DrawNode::create();
                    drawNode->drawPoint(Vec2(lista5[i]->getPosition()), 100, Color4F::MAGENTA);
                    this->addChild(drawNode);
                }
            }


            break;


        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:

            if (Ball->getPositionX() > 400 && Ball->getPositionY() < 700 && Ball->getPositionY() > 500) {
                Ball->runAction(action6);
            }
            if (Ball->getPositionX()>350) {
                Ball->runAction(action4);
            }
            if (Ball->getPositionY()< 300 && Ball->getPositionX()>350 )
            for (int i = 0; i < lista4.size(); ++i) {
                DrawNode *drawNode = DrawNode::create();
                drawNode->drawPoint(Vec2(lista4[i]->getPosition()), 100, Color4F::MAGENTA);
                this->addChild(drawNode);
            }

            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:

            Ball->runAction(action3);
            if (Ball->getPositionX()>400) {
                for (int i = 0; i < lista3.size(); ++i) {
                    DrawNode *drawNode = DrawNode::create();
                    drawNode->drawPoint(Vec2(lista3[i]->getPosition()), 100, Color4F::MAGENTA);
                    this->addChild(drawNode);
                }
            }
            break;




    }
    if (Ball->getPositionY() > 650 && (Ball->getPositionX()-650 < 100 || 650- Ball->getPositionX() < 100 )   ) {

        Scene *pScene = Level5::createScene();
        TransitionPageTurn *crosssfade = TransitionPageTurn::create(0.3, pScene, true);
        Director::getInstance()->replaceScene(crosssfade);

    }
}




