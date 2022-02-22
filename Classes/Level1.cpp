
#include "Level1.h"
#include "Level2.h"
USING_NS_CC;

Scene* Level1::createScene()
{

    auto scene =Scene::create();


    // 'layer' is an autorelease object
    auto layer = Level1::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}





// on "init" you need to initialize your instance
bool Level1::init() {
    //////////////////////////////
    // 1. super init first
    if (!Layer::init()) {
        return false;
    }


// 3



    auto origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getVisibleSize();

    LayerColor *_bgColor = LayerColor::create(Color4B::GRAY );
    this->addChild(_bgColor);



    float x = 725;
    float X = 100;
    for (int i = 0; i < 6; ++i) {
        x = x - X;
        BG = Sprite::create("Level2.png");
        BG->setPosition(Vec2(x,275 ));


        leftvector.push_back(BG);
        this->addChild(BG);

    }


    float y = 275;
    float Y = 100;
    for (int i = 0; i < 2; ++i) {
        y = y + Y;
        BG = Sprite::create("Level2.png");
        BG->setPosition(Vec2(155, y));
        upvector.push_back(BG);
        this->addChild(BG,0);
    }


    bg = Sprite::create("Level2Middle.png");
    bg->setPosition(Vec2(430, 375));
    this->addChild(bg,500);


    float xa = 155;
    float Xa = 100;
    for (int i = 0; i < 5; ++i) {
        xa = xa + Xa;
        BG = Sprite::create("Level2.png");
        BG->setPosition(Vec2(xa, 475));
        rightvector.push_back(BG);
        this->addChild(BG);
    }

// Ball
    Ball = Sprite::create("Ball.png");


    Ball->setPosition(Vec2(600, 275));
    auto position = Ball->getPosition();

    this->addChild(Ball,1);







    // Obstacle




    auto horizenatle = Sprite::create("Horizental.png");
    horizenatle->setPosition(Point(355 + origin.x, 200 + origin.y));

    this->addChild(horizenatle,1);

    auto horizenatle1 = Sprite::create("Horizental.png");
    horizenatle1->setPosition(Point(355 + origin.x, 550 + origin.y));


    this->addChild(horizenatle1,1);


    auto vertical = Sprite::create("Vertical.png");
    vertical->setPosition(Point(80 + origin.x, 375 + origin.y));

    this->addChild(vertical,1);




    auto vertical2 = Sprite::create("Vertical.png");
    vertical2->setPosition(Point(680 + origin.x, 375 + origin.y));

    this->addChild(vertical2,1);





    //Key Pressed

    auto eventListener = EventListenerKeyboard::create();
   eventListener->onKeyPressed = CC_CALLBACK_2 (Level1::keyPressed, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);


    return true;
}



void Level1::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event ) {


    auto action2 = MoveTo::create(0.1, Vec2(605, Ball->getPositionY()));
    auto action3 = MoveTo::create(0.1, Vec2(155, Ball->getPositionY()));
    auto action = MoveTo::create(0.1, Vec2(Ball->getPositionX(), 475 ));
    auto action1 = MoveTo::create(0.1, Vec2(Ball->getPositionX(), 278 ));
    auto  position  = Ball->getPosition();

    switch (keyCode) {

        case EventKeyboard::KeyCode::KEY_UP_ARROW:

            if (Ball->getPositionX()<400) {
                Ball->runAction(action);
                for (int i = 0; i <upvector.size() ; ++i) {
                    auto draw = DrawNode::create();
                    draw->drawPoint(Vec2(upvector[i]->getPosition()),100,Color4F::GRAY );

                    this->addChild(draw);
                    this->removeChild(upvector[i]);
                }
              upvector.clear();

            }


            break;

        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            if (Ball->getPositionX()<400) {
                Ball->runAction(action1);

            }
      break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            Ball->runAction(action2);
            if (Ball->getPositionY()>400){
                for (int i = 0; i <rightvector.size() ; ++i) {
                    auto draw = DrawNode::create();
                    draw->drawPoint(Vec2(rightvector[i]->getPosition()),100,Color4F::GRAY);

                    this->addChild(draw);
                    this->removeChild(rightvector[i]);

                }
                rightvector.clear();
            }


            break;

        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            Ball->runAction(action3);
            if (Ball->getPositionX()>400) {
                for (int i = 0; i < leftvector.size(); ++i) {
                    auto draw = DrawNode::create();
                    draw->drawPoint(Vec2(leftvector[i]->getPosition()),100,Color4F::GRAY);

                    this->addChild(draw);
                    this->removeChild(leftvector[i]);
                }
                leftvector.clear();
            }
            break;
    }


    if (  rightvector.size()==0 && leftvector.size()==0 && upvector.size()==0 && downvector.size()==0 ){

        Scene *pScene = Level2::createScene();
        TransitionPageTurn *crosssfade = TransitionPageTurn::create(0.5,pScene, true);
        Director::getInstance() ->replaceScene(crosssfade);

    }


}

