#ifndef __LIST_VERTICAL_ORDER_H__
#define __LIST_VERTICAL_ORDER_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class ListVerticalOrder : public cocos2d::extension::TableViewDataSource, 
                          public cocos2d::extension::TableViewDelegate
{
private:
    cocos2d::extension::TableView *tableView;

public:
    ListVerticalOrder();
    ~ListVerticalOrder();

    static ListVerticalOrder *create(const cocos2d::Size &size,
                                     const cocos2d::Vec2 &position);

    cocos2d::extension::TableView *getTableView() const;

    void reload();

    virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) override {}

    virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) override {}

    virtual void tableCellTouched(cocos2d::extension::TableView* table, 
                                  cocos2d::extension::TableViewCell* cell) override;

    virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, 
                                                ssize_t idx) override;

    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, 
                                                                ssize_t idx) override;

    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table) override;

};

#endif//__LIST_VERTICAL_ORDER_H__
