#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class SceneSettings;

class MenuScene : public cocos2d::Scene
{
private:
    cocos2d::Director *director;
    SceneSettings *settings;

public:
    CREATE_FUNC(MenuScene);

    ~MenuScene();

    static cocos2d::Scene *createScene();

    virtual bool init() override;

    void menuCloseCallback(cocos2d::Ref* pSender);

};

#endif//__MENU_SCENE_H__