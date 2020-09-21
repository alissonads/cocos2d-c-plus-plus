#ifndef __ITEM_LIST_H__
#define __ITEM_LIST_H__

#include "cocos2d.h"

class ItemList
{
private:
    cocos2d::Node *component;

private:
    ItemList();

public:
    //static ItemList build(); 

    ItemList &setComponent(cocos2d::Node *component);

    ItemList &addChild(cocos2d::Node *child);

    ItemList &setPosition(const cocos2d::Vec2 &position);

    ItemList &setAnchorPoint(const cocos2d::Vec2 &point);

    cocos2d::Node *create() const;

};

#endif//__ITEM_LIST_H__