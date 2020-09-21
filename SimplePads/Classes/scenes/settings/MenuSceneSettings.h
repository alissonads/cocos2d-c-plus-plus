#ifndef __MESNU_SCENE_SETTINGS_H__
#define __MESNU_SCENE_SETTINGS_H__

#include "base/SceneSettings.h"

class MenuSceneSettings : public SceneSettings
{
private:
    void configMenu();

public:
    MenuSceneSettings();

    virtual void config() override;
};

#endif//__MESNU_SCENE_SETTINGS_H__