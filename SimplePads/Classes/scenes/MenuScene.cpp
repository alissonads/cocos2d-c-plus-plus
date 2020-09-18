#include "MenuScene.h"
#include <iostream>

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

    //plano de fundo
    //auto background = DrawNode::create();
    //background->drawSolidRect(origin, winSize, Color4F(0.6,0.6,0.6,1.0));

    //this->addChild(background);

	auto tableView = TableView::create(this, Size(741, 500));
	tableView->setDirection(ScrollView::Direction::VERTICAL);
	tableView->setPosition(Vec2(20,-(winSize.height/2+100)));
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

        auto sprite = Sprite::create("images/menu_item_Back.png");
        
        sprite->setAnchorPoint(Vec2::ZERO);
        sprite->setPosition(Vec2::ZERO);
        
        cell->addChild(sprite);

        auto label = Label::createWithSystemFont(id, "Helvetica", 24.0);

        label->setPosition(Vec2::ZERO);
		label->setAnchorPoint(Vec2::ZERO);
        label->setTag(123);

        cell->addChild(label);
    }
    else 
    {
        auto label = (Label*)cell->getChildByTag(123);
        label->setString(id);
    }

    return cell;
}

ssize_t MenuScene::numberOfCellsInTableView(TableView *table) 
{
    return 5;
}