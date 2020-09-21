#include "MenuScene.h"
#include "settings/Background.h"
#include "settings/MenuSceneSettings.h"
#include <iostream>

#define PATH_IMAGE "images/"

USING_NS_CC;
USING_NS_CC_EXT;

/*MenuScene::MenuScene() :
        director(nullptr)
{}*/

MenuScene::~MenuScene() 
{
    if (settings)
    {
        delete settings;
    }
}

Scene *MenuScene::createScene()
{
    return MenuScene::create();
}

bool MenuScene::init() 
{
    if (!Scene::init())
        return false;

    director = Director::getInstance();

    auto winSize = director->getWinSize();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    settings = new MenuSceneSettings();
    settings->apply(this);

    return true;
}