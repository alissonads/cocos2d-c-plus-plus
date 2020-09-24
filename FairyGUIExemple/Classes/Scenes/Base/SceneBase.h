#ifndef __SCENE_BASE_H__
#define __SCENE_BASE_H__

#include "cocos2d.h"
#include "FairyGUI.h"

class Background;

class SceneBase : public cocos2d::Scene
{
protected:
    fairygui::GRoot *groot;
    fairygui::GComponent *view;
    Background *background;
    
protected:
    virtual void config() = 0;

public:
    SceneBase();
    virtual ~SceneBase();

    virtual bool init() override;
};

#endif//__SCENE_BASE_H__ 