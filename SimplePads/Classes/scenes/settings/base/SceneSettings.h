#ifndef __SCENE_SETTINGS_H__
#define __SCENE_SETTINGS_H__

#include "cocos2d.h"
#include <string>
//#include <iosfwd>

class Background;

class SceneSettings
{
protected:
    std::string title;
    std::string subtitle;
    Background *background;
    cocos2d::Menu *menu;

public:
    SceneSettings(const std::string title, const std::string subtitle = "");
    virtual ~SceneSettings();

    inline std::string getTitle() const { return title; }

    inline std::string getSubTitle() const { return subtitle; }

    virtual void config() = 0;

    virtual void apply(cocos2d::Scene *scene);
};

#endif//__SCENE_SETTINGS_H__