#include "ListVerticalOrder.h"
#include "ItemList.h"

#define PATH_IMAGE "images/"

USING_NS_CC;
USING_NS_CC_EXT;

ListVerticalOrder::ListVerticalOrder() :
                    tableView(nullptr)
{}


ListVerticalOrder::~ListVerticalOrder()
{
    if (tableView)
    {
        delete tableView;
        tableView = nullptr;
    }
}

ListVerticalOrder *ListVerticalOrder::create(const Size &size,
                                             const Vec2 &position)
{
    auto list = new ListVerticalOrder();
    list->tableView = TableView::create(list, size);
    list->tableView->setPosition(position);
    list->tableView->setDirection(ScrollView::Direction::VERTICAL);
	list->tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
	list->tableView->setDelegate(list);
	list->tableView->reloadData();
    list->tableView->setAnchorPoint(Vec2(0,1));

    return list;
}

TableView *ListVerticalOrder::getTableView() const
{
    return tableView;
}

void ListVerticalOrder::reload()
{
    tableView->reloadData();
}

void ListVerticalOrder::tableCellTouched(TableView* table, TableViewCell* cell)
{
    CCLOG("cell touched at index: %ld", static_cast<long>(cell->getIdx()));
}

Size ListVerticalOrder::tableCellSizeForIndex(TableView *table, ssize_t idx) 
{
    return Size(741, 120);
}

TableViewCell *ListVerticalOrder::tableCellAtIndex(TableView *table, ssize_t idx) 
{
    auto cell = table->dequeueCell();

    if (!cell) 
    {
        cell = new (std::nothrow) TableViewCell();
        cell->autorelease();

        auto item = ItemList();
        item.setMainComponent(Sprite::create(PATH_IMAGE "menu_item_Back.png"), Vec2(20, 0), Vec2::ZERO)
            .addComponent("main", "kit", Sprite::create(PATH_IMAGE "placeholder.png"), Vec2(10, 10), Vec2::ZERO);

        auto kitNameSize = item.getComponent("kit")->getContentSize();
        item.addComponent("kit", "kitLabel", Label::createWithTTF("Kit", "fonts/arial.ttf", 20.0f), Vec2(kitNameSize.width/2, kitNameSize.height/2+10))
            .addComponent("kit", "kitNameLabel", Label::createWithTTF("Nome", "fonts/arial.ttf", 20.0f), Vec2(kitNameSize.width/2, kitNameSize.height/2-10));

        auto menuItemSize = item.mainComponent()->getContentSize();
        item.addComponent("main", "adtDetail", Sprite::create(PATH_IMAGE "Rectangle 51.png"), Vec2(menuItemSize.width, 0), Vec2(1, 0));

        auto adtDetailSize = item.getComponent("adtDetail")->getContentSize();
        item.addComponent("adtDetail", "arrow", Sprite::create(PATH_IMAGE "down_arrow.png"), Vec2(adtDetailSize.width/2, adtDetailSize.height/2))
            .addComponent("main", "insp", Label::createWithTTF("Inspirado em", "fonts/arial.ttf", 12.0f), Vec2(menuItemSize.width/4 + 20, menuItemSize.height/2 + 40), Vec2(0, 1))
            .addComponent("main", "MusicName", Label::createWithTTF("Nome da Musica", "fonts/arial.ttf", 18.0f), Vec2(menuItemSize.width/4 + 20, menuItemSize.height/2), Vec2(0, 0.5f))
            .addComponent("main", "artistName", Label::createWithTTF("Nome do Artista", "fonts/arial.ttf", 14.0f), Vec2(menuItemSize.width/4 + 20, menuItemSize.height/2-10), Vec2(0, 1))
            .addComponent("main", "bar", Sprite::create(PATH_IMAGE "Rectangle 52.png"), Vec2(menuItemSize.width/4 + 20, menuItemSize.height/2 + 20), Vec2(0, 0.5f));
            
        cell->addChild(item.mainComponent());

        //if (idx > 20) return cell;
        
        /*auto menuItem = Sprite::create(PATH_IMAGE "menu_item_Back.png");
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

        cell->addChild(menuItem);*/
    }

    return cell;
}

ssize_t ListVerticalOrder::numberOfCellsInTableView(TableView *table) 
{
    return 25;
}