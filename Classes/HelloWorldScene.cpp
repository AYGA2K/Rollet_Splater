#include "HelloWorldScene.h"
#include "Level1.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto Background = Sprite::create("Background1.jpg");

    Background->setPosition(Point(100, 0));
    Background->setScale(0.7);

    this->addChild(Background);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    Director::getInstance()->getOpenGLView()->setFrameSize(800,1000 );
    Director::getInstance()->getOpenGLView()->setDesignResolutionSize(800, 1000, ResolutionPolicy::EXACT_FIT);


    auto menu_item = MenuItemImage::create("Play.png", "Play.png", CC_CALLBACK_1(HelloWorld::Play, this));
    menu_item->setScale(0.2);

    menu_item->setPosition(Point(400, 500));



    auto *menu = Menu::create(menu_item, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);



    return true;
}

void HelloWorld::Play(cocos2d::Ref *pSender)
{


    auto scene = Level1::createScene();

    Director::getInstance()->replaceScene(scene);
}


