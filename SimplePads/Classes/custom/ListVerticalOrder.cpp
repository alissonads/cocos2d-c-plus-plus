#include "ListVerticalOrder.h"

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

ListVerticalOrder *ListVerticalOrder::create(TableViewDataSource *dataSource, 
                                             TableViewDelegate *viewDelegate,
                                             const Size &size,
                                             const Vec2 &position)
{
    auto list = new ListVerticalOrder();
    list->tableView = TableView::create(dataSource, size);
    list->tableView->setPosition(position);
    list->tableView->setDirection(ScrollView::Direction::VERTICAL);
	list->tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
	list->tableView->setDelegate(viewDelegate);
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