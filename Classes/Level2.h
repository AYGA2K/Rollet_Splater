

#include "cocos2d.h"



class Level2: public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Level2);

    cocos2d::Sprite *Ball;


    void GoBack(Ref *pSender);

    void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event );

    bool onContactBegin(cocos2d::PhysicsContact &contact);

    std::vector<cocos2d::Sprite *>lista1, lista2,lista3, lista4,lista5;


};



