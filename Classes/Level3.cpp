
#include "Level3.h"
#include "Level4.h"






USING_NS_CC;

Scene* Level3::createScene()
{

    auto scene =Scene::create();


    // 'layer' is an autorelease object
    auto layer = Level3::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}





// on "init" you need to initialize your instance
bool Level3::init() {
    //////////////////////////////
    // 1. super init first
    if (!Layer::init()) {
        return false;
    }


// 3



    auto origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getVisibleSize();


    LayerColor *_bgColor = LayerColor::create(Color4B::GRAY);
    this->addChild(_bgColor, -10);



// Ball
    float y = 125;
    float Y = 100;
    for (int i = 0; i < 7; ++i) {
        y = y + Y;
        BG = Sprite::create("BG1.png");
        BG->setPosition(Vec2(155, y));

        upvector.push_back(BG);
        this->addChild(BG);


    }

    float upy = 225;
    float upY = 100;
    for (int i = 0; i < 4; ++i) {
        upy = upy + upY;
        BG = Sprite::create("BG1.png");
        BG->setPosition(Vec2(355, upy));

        upvector2.push_back(BG);
        this->addChild(BG);


    }

    bg = Sprite::create("Obs.png");
    bg->setPosition(Vec2(485,470));
    this->addChild(bg);



    float x = 205;
    float X = 100;
    for (int i = 0; i < 4; ++i) {
        x = x + X;
        BG = Sprite::create("BG1.png");
        BG->setPosition(Vec2(x, 825));
        rightvector.push_back(BG);
        this->addChild(BG);
    }
    bg1 = Sprite::create("bg.png");
    bg1->setPosition(Vec2(230, 825));
    rightvector.push_back(bg1);
    this->addChild(bg1);


    float ya = 825;
    float Ya = 100;
    for (int i = 0; i < 6; ++i) {
        ya = ya - Ya;
        BG = Sprite::create("BG1.png");
        BG->setPosition(Vec2(605, ya));

        this->setColor(Color3B(255, 0, 0));

        downvector.push_back(BG);
        this->addChild(BG);
    }


    float xa = 605;
    float Xa = 100;
    for (int i = 0; i < 3; ++i) {
        xa = xa - Xa;
        BG = Sprite::create("BG1.png");
        BG->setPosition(Vec2(xa, 225));
        leftvector.push_back(BG);
        this->addChild(BG);
    }
    float oby=125;
    float  obY=100;
    for (int i = 0; i <6 ; ++i) {
         oby=oby+obY;
        BG = Sprite::create("Obstacle.png");
        BG->setPosition(Vec2(255, oby));

        this->addChild(BG,1);

    }
    float obx=205;
    float  obX=100;
    for (int i = 0; i <3 ; ++i) {
        obx=obx+obY;
        BG = Sprite::create("Obstacle.png");
        BG->setPosition(Vec2(obx, 725));

        this->addChild(BG);

    }

    Ball = Sprite::create("Ball.png");


    Ball->setPosition(Vec2(155, 225));
    auto position = Ball->getPosition();

    this->addChild(Ball);

    Ball->setLocalZOrder(50);









    // Obstacle




    auto horizenatle = Sprite::create("Horizental.png");
    horizenatle->setPosition(Point(355 + origin.x, 150 + origin.y));

    this->addChild(horizenatle);

    auto horizenatle1 = Sprite::create("Horizental.png");
    horizenatle1->setPosition(Point(355 + origin.x, 900 + origin.y));


    this->addChild(horizenatle1);


    auto vertical = Sprite::create("Vertical.png");
    vertical->setPosition(Point(80 + origin.x, 325 + origin.y));

    this->addChild(vertical);


    auto vertical1 = Sprite::create("Vertical.png");
    vertical1->setPosition(Point(80 + origin.x, 725 + origin.y));

    this->addChild(vertical1);

    auto vertical2 = Sprite::create("Vertical.png");
    vertical2->setPosition(Point(680 + origin.x, 325 + origin.y));

    this->addChild(vertical2);

    auto vertical3 = Sprite::create("Vertical.png");
    vertical3->setPosition(Point(680 + origin.x, 725 + origin.y));

    this->addChild(vertical3);




    //Key Pressed

    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = CC_CALLBACK_2 (Level3::keyPressed, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);


    return true;
}




void Level3::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event ) {


    auto color=TintTo::create(0.1,100,0,0);
    auto action2 = MoveTo::create(0.1, Vec2(605, Ball->getPositionY()));
    auto action3 = MoveTo::create(0.1, Vec2(355, Ball->getPositionY()));
    auto action4 = MoveTo::create(0.1, Vec2(155, Ball->getPositionY()));
    auto action = MoveTo::create(0.1, Vec2(Ball->getPositionX(), 825 ));
    auto action5 = MoveTo::create(0.1, Vec2(Ball->getPositionX(), 25 ));
    auto action1 = MoveTo::create(0.1, Vec2(Ball->getPositionX(), 225 ));
    auto  position  = Ball->getPosition();

    switch (keyCode) {

        case EventKeyboard::KeyCode::KEY_UP_ARROW:

            Ball->runAction(action);

            if (Ball->getPositionX() < 400 && Ball->getPositionY() <400  ) {


                for (int i = 0; i < upvector.size(); ++i) {

                    auto draw = DrawNode::create();
                    draw->drawPoint(Vec2(upvector[i]->getPosition()),100,Color4F::YELLOW);

                    this->addChild(draw);

                    this->removeChild(upvector[i]);


                }



                upvector.clear();
            }
            if (Ball->getPositionX() > 400 && Ball->getPositionY() <400   ) {

                this->removeChild(rightvector[3]);


                for (int i = 0; i < downvector.size(); ++i) {

                    auto draw = DrawNode::create();
                    draw->drawPoint(Vec2(downvector[i]->getPosition()),100,Color4F::YELLOW);

                    this->addChild(draw);
                    this->removeChild(downvector[i]);


                }
                downvector.clear();

            }

            if (Ball->getPositionX()<400 && Ball->getPositionX()>250 && Ball->getPositionY()&&400 ){
                Ball->runAction(action5);
                for (int i = 0; i <upvector2.size() ; ++i) {
                    auto draw = DrawNode::create();
                    draw->drawPoint(Vec2(upvector2[i]->getPosition()),100,Color4F::YELLOW);

                    this->addChild(draw);
                    this->removeChild(upvector2[i]);

                }
                upvector2.clear();
            }


            break;

        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            Ball->runAction(action1);

            if (Ball->getPositionX()>400 && Ball->getPositionY()>400  ) {
                for (int i = 0; i < downvector.size(); ++i) {
                    auto draw = DrawNode::create();
                    draw->drawPoint(Vec2(downvector[i]->getPosition()),100,Color4F::YELLOW);
                    this->addChild(draw);
                    this->removeChild(downvector[i]);
                }
                downvector.clear();
            }
            if (Ball->getPositionX()<400 && Ball->getPositionY()>400 ){

                for (int i = 0; i < upvector.size(); ++i) {
                    auto draw = DrawNode::create();
                    draw->drawPoint(Vec2(upvector[i]->getPosition()),100,Color4F::YELLOW);
                    this->addChild(draw);
                    this->removeChild(upvector[i]);

                }

                upvector.clear();
            }

            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:

            if (Ball->getPositionY()>400 && Ball->getPositionX() <400  ) {
                Ball->runAction(action2);
                for (int i = 0; i < rightvector.size(); ++i) {
                    auto draw = DrawNode::create();
                    draw->drawPoint(Vec2(rightvector[i]->getPosition()),100,Color4F::YELLOW);
                    this->addChild(draw);
                    this->removeChild(rightvector[i]);


                }
                rightvector.clear();
            }

            if (Ball->getPositionX()> 300 && Ball->getPositionY()<400){
                Ball->runAction(action2);
            }



            break;

        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:


            if (Ball->getPositionY()>400 && Ball->getPositionX()>400) {
                Ball->runAction(action4);

                this->removeChild(upvector[6]);

                for (int i = 0; i < rightvector.size(); ++i) {

                    this->removeChild(rightvector[i]);


                }
                rightvector.clear();
            }


            if (Ball->getPositionY()<400 && Ball->getPositionX()>400) {
                Ball->runAction(action3);


                for (int i = 0; i < leftvector.size(); ++i) {

                    auto draw = DrawNode::create();
                    draw->drawPoint(Vec2(leftvector[i]->getPosition()),100,Color4F::YELLOW);
                    this->addChild(draw);

                    this->removeChild(leftvector[i]);


                }
                leftvector.clear();
            }



            break;
    }


    if (  rightvector.size()==0 && leftvector.size()==0 && upvector.size()==0 && downvector.size()==0 &&upvector2.size()==0 ){

        Scene *pScene = Level4::createScene();
        TransitionPageTurn *crosssfade = TransitionPageTurn::create(0.5,pScene, true);
        Director::getInstance() ->replaceScene(crosssfade);

    }


}











