#include "MenuScene.h"
#include "settings/Background.h"
#include <iostream>

#define PATH_IMAGE "images/"

USING_NS_CC;
USING_NS_CC_EXT;

/*MenuScene::MenuScene() :
        director(nullptr)
{}*/

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

    ///>>Encapsular
    /*********************** cria e configura o botao de sair *************************************/
    auto closeItem = MenuItemImage::create(PATH_IMAGE "bck_close.png",
                                           PATH_IMAGE "bck_close.png",
                                           /*CC_CALLBACK_1(MenuScene::menuCloseCallback, this)*/
                                           [](Ref* pSender) {
                                               Director::getInstance()->end();
                                           });
    closeItem->setAnchorPoint(Vec2(0, 1));
    auto closeItemSize = closeItem->getContentSize();
    closeItem->setPosition(Vec2(10, winSize.height - closeItemSize.height));

    //settings = new MenuSceneSettings();
    //settings->apply(this);

    /***********************************************************************************************/
    //cria o menu
    auto menu = Menu::create(closeItem, NULL);
    //posiciona o menu
    menu->setPosition(Vec2::ZERO);
    //adiciona o menu a arvore
    this->addChild(menu, 1);

    //cria o sprite do x do botão
    auto x = Sprite::create(PATH_IMAGE "x.png");
    //posiciona o botao com relação a imagem de fundo do botão
    x->setPosition(Vec2(closeItemSize.width/2,closeItemSize.height/2));
    //adiciona ao botão
    closeItem->addChild(x);
    ////////////////////////>>

    //plano de fundo
    this->addChild(Background::createBgSolidColorI(36,43,46)->getNode());
    
    //conteiner de itens do menu musical
	auto tableView = TableView::create(this, Size(400, 500));
	tableView->setDirection(ScrollView::Direction::VERTICAL);
	tableView->setPosition(Vec2(65,-(winSize.height/2+130)));
	tableView->setDelegate(this);
	tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
	this->addChild(tableView);
	tableView->reloadData();

    return true;
}

void MenuScene::scrollViewDidScroll(ScrollView* view) {}

void MenuScene::scrollViewDidZoom(ScrollView* view) {}

void MenuScene::tableCellTouched(TableView* table, TableViewCell* cell)
{
    CCLOG("cell touched at index: %ld", static_cast<long>(cell->getIdx()));
}

Size MenuScene::tableCellSizeForIndex(TableView *table, ssize_t idx) 
{
    return Size(741, 100);
}

TableViewCell* MenuScene::tableCellAtIndex(TableView *table, ssize_t idx) 
{
    auto cell = table->dequeueCell();
    auto id = StringUtils::format("%ld", static_cast<long>(idx));

    if (!cell) 
    {
        cell = new (std::nothrow) TableViewCell();
        cell->autorelease();

        auto menuItem = Sprite::create(PATH_IMAGE "menu_item_Back.png");
        menuItem->setAnchorPoint(Vec2::ZERO);
        menuItem->setPosition(Vec2::ZERO);

        auto menuItemSize = menuItem->getContentSize();

        auto kitName = Sprite::create(PATH_IMAGE "placeholder.png");
        kitName->setAnchorPoint(Vec2::ZERO);
        kitName->setPosition(Vec2(10, 10));

        menuItem->addChild(kitName, 0);

        auto adtDetail = Sprite::create(PATH_IMAGE "Rectangle 51.png");
        adtDetail->setAnchorPoint(Vec2(1, 0));
        adtDetail->setPosition(Vec2(menuItemSize.width, 0));

        auto arrow = Sprite::create(PATH_IMAGE "down_arrow.png");
        auto adtDetailSize = adtDetail->getContentSize();

        arrow->setPosition(Vec2(adtDetailSize.width/2, adtDetailSize.height/2));
        adtDetail->addChild(arrow);

        menuItem->addChild(adtDetail, 1);

        cell->addChild(menuItem);
    }

    return cell;
}

ssize_t MenuScene::numberOfCellsInTableView(TableView *table) 
{
    return 20;
}

void MenuScene::menuCloseCallback(Ref* pSender)
{
    director->end();
}