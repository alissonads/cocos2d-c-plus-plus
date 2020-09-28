#include "GameScene.h"
#include "MenuScene.h"

USING_NS_CC;
USING_NS_FGUI;

GameScene::GameScene() : SceneBase()
{}

GameScene::~GameScene()
{
}

void GameScene::close()
{
    view->getChild("btn_menu")->addClickListener([this](EventContext*) {
        auto scene = TransitionFade::create(0.5f, MenuScene::createScene());
        Director::getInstance()->replaceScene(scene);
    });
}

Scene* GameScene::createScene()
{
    return GameScene::create();
}

void GameScene::config()
{
    UIPackage::addPackage("images/Game_Pads");
    view = UIPackage::createObject("Game_Pads", "main")->as<GComponent>();
    groot->addChild(view);

    close();
}

void GameScene::setKitName(const std::string &kitName)
{
    this->kitName = kitName;
}

std::string GameScene::getKitName() const
{
    return kitName;
}