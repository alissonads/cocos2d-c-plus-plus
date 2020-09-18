#ifndef __CUSTOM_TABLE_VIEW_DATA_SOURCE_H__
#define __CUSTOM_TABLE_VIEW_DATA_SOURCE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class CustomTableViewDataSource : public cocos2d::extension::TableViewDataSource
{
public:
    virtual cocos2d::extension::TableViewCell *tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
    
    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);
};

#endif //__CUSTOM_TABLE_VIEW_DATA_SOURCE_H__