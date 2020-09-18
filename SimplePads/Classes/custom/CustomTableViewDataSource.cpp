#include "CustomTableViewDataSource.h"

USING_NS_CC;
USING_NS_CC_EXT;

TableViewCell* CustomTableViewDataSource::tableCellAtIndex(TableView *table, ssize_t idx)
{
    auto string = StringUtils::format("%ld", static_cast<long>(idx));
    TableViewCell *cell = table->dequeueCell();
    if (!cell) 
    {
        cell = new (std::nothrow) TableViewCell();
        cell->autorelease();
        auto sprite = Sprite::create("Images/Icon.png");
        sprite->setAnchorPoint(Vec2::ZERO);
        sprite->setPosition(Vec2(0, 0));
        cell->addChild(sprite);

        auto label = Label::createWithSystemFont(string, "Helvetica", 20.0);
        label->setPosition(Vec2::ZERO);
		label->setAnchorPoint(Vec2::ZERO);
        label->setTag(123);
        cell->addChild(label);
    }
    else
    {
        auto label = (Label*)cell->getChildByTag(123);
        label->setString(string);
    }


    return cell;
}

ssize_t CustomTableViewDataSource::numberOfCellsInTableView(TableView *table)
{
    return 20;
}