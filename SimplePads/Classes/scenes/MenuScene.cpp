#include "MenuScene.h"
#include "settings/Background.h"
#include "settings/MenuSceneSettings.h"
#include "custom/ListVerticalOrder.h"
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

    settings = new MenuSceneSettings();
    settings->apply(this);

    auto winSize = Director::getInstance()->getWinSize();

    auto list = ListVerticalOrder::create(Size(winSize.width, 720), Vec2(0, 0));
    this->addChild(list->getTableView());
    list->reload();

    return true;
}