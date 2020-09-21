#ifndef __MESNU_SCENE_SETTINGS_H__
#define __MESNU_SCENE_SETTINGS_H__

#include "base/SceneSettings.h"
#include "extensions/cocos-ext.h"

class ListVerticalOrder;

class MenuSceneSettings : public SceneSettings, 
                          public cocos2d::extension::TableViewDataSource, 
                          public cocos2d::extension::TableViewDelegate
{
private:
    ListVerticalOrder *list;

private:
    void configMenu();

public:
    MenuSceneSettings();
    ~MenuSceneSettings();

    virtual void config() override;

    virtual void apply(cocos2d::Scene *scene);

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

#endif//__MESNU_SCENE_SETTINGS_H__