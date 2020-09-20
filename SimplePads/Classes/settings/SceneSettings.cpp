#include "SceneSettings.h"
#include "Background.h"

USING_NS_CC;

SceneSettings::SceneSettings() :
                title(""),
                subtitle(""),
                background(nullptr)
{}

SceneSettings::SceneSettings(const std::string title, const std::string subtitle) :
                title(title),
                subtitle(subtitle),
                background(nullptr)
{}

SceneSettings::~SceneSettings() 
{
    if (background)
    {
        delete background;
        background = nullptr;
    }
}

void SceneSettings::apply(cocos2d::Scene *scene)
{
    config();
    scene->addChild(background->getNode());
    //scene->addChild(this->menu->getNode());
}