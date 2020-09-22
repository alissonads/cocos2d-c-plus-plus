#include "GameSceneSettings.h"
#include "Background.h"

USING_NS_CC;

GameSceneSettings::GameSceneSettings() :
                   SceneSettings("Game")
{
}

void GameSceneSettings::configMenu()
{
    //cria o menu
    menu = Menu::create();
    //posiciona o menu
    menu->setPosition(Vec2::ZERO);

    auto director = Director::getInstance();
    auto winSize = director->getWinSize();

    //adiciona os itens do menu
    auto btnMenu = MenuItemImage::create(PATH_IMAGE "btn_menu.png",
                                         PATH_IMAGE "btn_menu.png",
                                         [](Ref* pSender) {
                                               Director::getInstance()->end();
                                          });

    btnMenu->setAnchorPoint(Vec2(0, 1));
    btnMenu->setPosition(Vec2(40, winSize.height - 15));

    menu->addChild(btnMenu);

    auto btnSize = btnMenu->getContentSize();

    //Kit Name
    TTFConfig ttfConfig("fonts/arial.ttf", 20);
    auto label = Label::createWithTTF(ttfConfig, "Kit");
    menu->addChild(label);
    label->setPosition(Vec2(btnSize.width + 80, 
                            winSize.height - (btnSize.height / 2) - 15));
    label->setOpacity(0.7f*255);

    auto labelSize = label->getContentSize();
    auto labelPosition = label->getPosition();

    label = Label::createWithTTF(ttfConfig, "NAME");
    menu->addChild(label);
    label->setAnchorPoint(Vec2(0, 0.5f));
    label->setPosition(Vec2(labelPosition.x + labelSize.width - 10, 
                            winSize.height - (btnSize.height / 2) - 15));
    label->enableBold();

    auto line = Sprite::create(PATH_IMAGE "line.png");
    line->setPosition(Vec2(winSize.width / 2, winSize.height - btnSize.height - 30));
    menu->addChild(line);
}

void GameSceneSettings::config()
{
    configMenu();

    background = Background::createBgSolidColorI(36,43,46);
}