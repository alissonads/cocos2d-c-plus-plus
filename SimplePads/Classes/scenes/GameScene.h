#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include <vector>
#include <string>

class SceneSettings;

class GameScene : public cocos2d::Scene
{
private:
    SceneSettings *settings;
    std::vector<std::string> imageFilesNames;

private:
    void createPads();

public:
    CREATE_FUNC(GameScene);

    ~GameScene();

    static cocos2d::Scene *createScene();

    virtual bool init() override;
};

#endif//__GAME_SCENE_H__