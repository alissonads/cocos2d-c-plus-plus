#include "GameScene.h"
#include "settings/GameSceneSettings.h"
#include "custom/GridTiles.h"
#include <iostream>

USING_NS_CC;

GameScene::~GameScene()
{
    if (settings)
    {
        delete settings;
        settings = nullptr;
    }

    imageFilesNames.clear();
}

void GameScene::createPads()
{
    int pads[4][3] = { {0, 0, 0},  
                       {1, 2, 1},
                       {2, 2, 2},
                       {3, 3, 3} 
                   };
    auto director = Director::getInstance();
    auto winSize = director->getWinSize();
    auto origin = director->getVisibleOrigin();
    auto grid = GridTiles();

    //CCLOGWARN("WinSize-> width: %f, height: %f", winSize.width,winSize.height);

    grid.addImages({PATH_IMAGE "blue.png", PATH_IMAGE "green.png", PATH_IMAGE "orange.png", PATH_IMAGE "red.png"})
        .setSizeTiles(Size(130, 130))
        .setOffset(Vec2(11, 11))
        .setInitPos(Vec2(origin.x, winSize.height - 150))
        .setRenderingMap(*pads, 4, 3)
        .setAnchorPoint(Vec2(0, 1))
        .apply(*this);
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

    createPads();

    return true;
}