#ifndef __GAME_SCENE_SETTINGS_H__
#define __GAME_SCENE_SETTINGS_H__

#include "base/SceneSettings.h"

class GameSceneSettings : public SceneSettings
{
private:

    void configMenu();

public:
    GameSceneSettings();
    
    virtual void config() override;

};

#endif//__GAME_SCENE_SETTINGS_H__