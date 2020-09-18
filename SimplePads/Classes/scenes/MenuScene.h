#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class MenuScene : public cocos2d::Scene, 
                  public cocos2d::extension::TableViewDataSource, 
                  public cocos2d::extension::TableViewDelegate
{
private:
    cocos2d::Director *director;

public:
    CREATE_FUNC(MenuScene);

    static cocos2d::Scene *createScene();

    virtual bool init() override;

    virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) override;

    virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) override;

    virtual void tableCellTouched(cocos2d::extension::TableView* table, 
                                  cocos2d::extension::TableViewCell* cell) override;

    virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, 
                                                ssize_t idx) override;

    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, 
                                                                ssize_t idx) override;

    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table) override;

};

#endif//__MENU_SCENE_H__