#include "GameScene.h"
#include "settings/GameSceneSettings.h"

USING_NS_CC;

GameScene::~GameScene()
{
    if (settings)
    {
        delete settings;
        settings = nullptr;
    }
}

Scene *GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if (!Scene::init())
        return false;

    //criar setting
    settings = new GameSceneSettings();
    settings->apply(this);

    return true;
}