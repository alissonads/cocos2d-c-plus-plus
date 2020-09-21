#include "SceneSettings.h"
#include "../Background.h"

USING_NS_CC;

SceneSettings::SceneSettings(const std::string title, const std::string subtitle) :
                title(title),
                subtitle(subtitle),
                background(nullptr),
                menu(nullptr)
{}

SceneSettings::~SceneSettings() 
{
    if (background)
    {
        delete background;
        background = nullptr;
    }
    if (menu)
    {
        delete menu;
        menu = nullptr;
    }
}

void SceneSettings::apply(cocos2d::Scene *scene)
{
    config();
    
    if (menu)
        scene->addChild(menu, 1);
    if (background)
        scene->addChild(background->getNode());
}