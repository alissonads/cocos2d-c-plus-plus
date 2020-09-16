#ifndef __SCENE1_H__
#define __SCENE1_H__

#include "cocos2d.h"

class Scene1 : public cocos2d::Scene  
{
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();

    virtual void update(float delta);

    void menuCloseCallback(cocos2d::Ref *sender);

    CREATE_FUNC(Scene1);
};

#endif // __SCENE1_H__