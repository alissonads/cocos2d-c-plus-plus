#include "SceneBase.h"
#include "../Background.h"

USING_NS_CC;
USING_NS_FGUI;

SceneBase::SceneBase() :
            groot(nullptr),
            view(nullptr),
            background(nullptr)
{}

SceneBase::~SceneBase() 
{
    CC_SAFE_RELEASE(groot);
}

bool SceneBase::init()
{
    if (Scene::init())
    {
        background = Background::createBgSolidColorI(36,43,46);
        this->addChild(background->getNode());

        groot = GRoot::create(this);
        groot->retain();

        config();

        return true;
    }
    return false;
}