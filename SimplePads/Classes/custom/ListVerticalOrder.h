#ifndef __LIST_VERTICAL_ORDER_H__
#define __LIST_VERTICAL_ORDER_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class ListVerticalOrder
{
private:
    cocos2d::extension::TableView *tableView;

public:
    ListVerticalOrder();
    ~ListVerticalOrder();

    static ListVerticalOrder *create(cocos2d::extension::TableViewDataSource *dataSource, 
                                     cocos2d::extension::TableViewDelegate *viewDelegate,
                                     const cocos2d::Size &size,
                                     const cocos2d::Vec2 &position);

    cocos2d::extension::TableView *getTableView() const;

    void reload();

};

#endif//__LIST_VERTICAL_ORDER_H__
