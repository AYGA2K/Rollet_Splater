
#include "cocos2d.h"
#include<algorithm>

class Level1 : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Level1);

    cocos2d::Sprite *Ball;
    cocos2d::Sprite *BG;
    cocos2d::Sprite *bg;
    cocos2d::Sprite *bg1;

    cocos2d::Sprite *temp;



    static  int win ;

    void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event );




    void Check();

    std::vector<cocos2d::Sprite*>upvector;
    std::vector<cocos2d::Sprite*>downvector;
    std::vector<cocos2d::Sprite*>leftvector;
    std::vector<cocos2d::Sprite*>rightvector;


};

