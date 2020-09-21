#include "MenuSceneSettings.h" 
#include "Background.h"

#define PATH_IMAGE "images/"

USING_NS_CC;

MenuSceneSettings::MenuSceneSettings() :
                   SceneSettings("Menu Scene")
{}

void MenuSceneSettings::config()
{
    //cria o menu
    menu = Menu::create();
    //posiciona o menu
    menu->setPosition(Vec2::ZERO);
    //adiciona o menu a arvore

    //adiciona os itens do menu
    auto closeItem = MenuItemImage::create(PATH_IMAGE "bck_close.png",
                                           PATH_IMAGE "bck_close.png",
                                           [](Ref* pSender) {
                                               Director::getInstance()->end();
                                           });
    auto director = Director::getInstance();
    auto winSize = director->getWinSize();

    closeItem->setAnchorPoint(Vec2(0, 1));
    auto closeItemSize = closeItem->getContentSize();
    closeItem->setPosition(Vec2(10, winSize.height - closeItemSize.height));

    auto x = Sprite::create(PATH_IMAGE "x.png");
    //posiciona o botao com relação a imagem de fundo do botão
    x->setPosition(Vec2(closeItemSize.width/2,closeItemSize.height/2));
    //adiciona ao botão
    closeItem->addChild(x);

    menu->addChild(closeItem);

    background = Background::createBgSolidColorI(36,43,46);
}

