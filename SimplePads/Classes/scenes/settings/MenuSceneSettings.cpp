#include "MenuSceneSettings.h" 
#include "Background.h"
#include "custom/ListVerticalOrder.h"

#define PATH_IMAGE "images/"

USING_NS_CC;
USING_NS_CC_EXT;

MenuSceneSettings::MenuSceneSettings() :
                   SceneSettings("Menu Scene"),
                   list(nullptr)
{}

MenuSceneSettings::~MenuSceneSettings()
{
    /*if (list)
    {
        delete list;
        list = nullptr;
    }*/
}

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
    closeItem->setPosition(Vec2(40, winSize.height - 10));

    auto x = Sprite::create(PATH_IMAGE "x.png");

    //closeItem->setScale(0.8f);

    //posiciona o botao com relação a imagem de fundo do botão
    x->setPosition(Vec2(closeItemSize.width/2,closeItemSize.height/2));
    //adiciona ao botão
    closeItem->addChild(x);

    menu->addChild(closeItem);

    auto bgSize = director->getVisibleSize();
    bgSize.height = bgSize.height -20;

    background = Background::createBgSolidColorI(36,43,46);

    list = ListVerticalOrder::create(this, this, Size(741, 650), Vec2(22, 0));
}

void MenuSceneSettings::apply(cocos2d::Scene *scene)
{
    SceneSettings::apply(scene);

    if (list)
    {
        scene->addChild(list->getTableView());
        list->reload();
    }
}

void MenuSceneSettings::tableCellTouched(TableView* table, TableViewCell* cell)
{
    CCLOG("cell touched at index: %ld", static_cast<long>(cell->getIdx()));
}

Size MenuSceneSettings::tableCellSizeForIndex(TableView *table, ssize_t idx) 
{
    return Size(741, 110);
}

TableViewCell *MenuSceneSettings::tableCellAtIndex(TableView *table, ssize_t idx) 
{
    auto cell = table->dequeueCell();

    if (!cell) 
    {
        cell = new (std::nothrow) TableViewCell();
        cell->autorelease();

        //if (idx > 20) return cell;
        
        auto menuItem = Sprite::create(PATH_IMAGE "menu_item_Back.png");
        menuItem->setAnchorPoint(Vec2::ZERO);
        menuItem->setPosition(Vec2::ZERO);

        auto menuItemSize = menuItem->getContentSize();

        //Kit
        auto kitName = Sprite::create(PATH_IMAGE "placeholder.png");
        kitName->setAnchorPoint(Vec2::ZERO);
        kitName->setPosition(Vec2(10, 10));

        auto kitNameSize = kitName->getContentSize();

        auto kitLabel = Label::createWithTTF("Kit", "fonts/arial.ttf", 20.0f);
        kitLabel->setPosition(kitNameSize.width/2, kitNameSize.height/2+10);
        kitName->addChild(kitLabel);

        kitLabel = Label::createWithTTF("Nome", "fonts/arial.ttf", 20.0f);
        kitLabel->setPosition(kitNameSize.width/2, kitNameSize.height/2-10);
        kitName->addChild(kitLabel);

        menuItem->addChild(kitName, 0);
        //fim kit>>

        auto adtDetail = Sprite::create(PATH_IMAGE "Rectangle 51.png");
        adtDetail->setAnchorPoint(Vec2(1, 0));
        adtDetail->setPosition(Vec2(menuItemSize.width, 0));

        auto arrow = Sprite::create(PATH_IMAGE "down_arrow.png");
        auto adtDetailSize = adtDetail->getContentSize();

        arrow->setPosition(Vec2(adtDetailSize.width/2, adtDetailSize.height/2));
        adtDetail->addChild(arrow);

        menuItem->addChild(adtDetail, 1);

        //descrição
        auto descLabel = Label::createWithTTF("Inspirado em", "fonts/arial.ttf", 12.0f);
        descLabel->setAnchorPoint(Vec2(0, 1));
        descLabel->setPosition(Vec2(menuItemSize.width/4 + 20, menuItemSize.height/2 + 40));
        menuItem->addChild(descLabel);

        auto descLabelSize = descLabel->getContentSize();

        descLabel = Label::createWithTTF("Nome da Musica", "fonts/arial.ttf", 18.0f);
        descLabel->setAnchorPoint(Vec2(0, 0.5f));
        descLabel->setPosition(Vec2(menuItemSize.width/4 + 20, menuItemSize.height/2));
        menuItem->addChild(descLabel);

        descLabel = Label::createWithTTF("Nome do Artista", "fonts/arial.ttf", 14.0f);
        descLabel->setAnchorPoint(Vec2(0, 1));
        descLabel->setPosition(Vec2(menuItemSize.width/4 + 20, menuItemSize.height/2-10));
        menuItem->addChild(descLabel);

        auto bar = Sprite::create(PATH_IMAGE "Rectangle 52.png");
        bar->setAnchorPoint(Vec2(0, 0.5f));
        bar->setPosition(menuItemSize.width/4 + 20, menuItemSize.height/2 + 20);

        menuItem->addChild(bar);

        cell->addChild(menuItem);
    }

    return cell;
}

ssize_t MenuSceneSettings::numberOfCellsInTableView(TableView *table) 
{
    return 25;
}

