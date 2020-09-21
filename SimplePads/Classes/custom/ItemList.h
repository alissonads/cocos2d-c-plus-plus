#ifndef __ITEM_LIST_H__
#define __ITEM_LIST_H__

#include "cocos2d.h"
#include <unordered_map>
#include <string>

class ItemList
{
private:
    typedef std::unordered_map<std::string, cocos2d::Node*> Components;
    Components components;

public:
    ItemList();
    ~ItemList();

    ItemList &setMainComponent(cocos2d::Node *component, 
                               const cocos2d::Vec2 &position = cocos2d::Vec2::ZERO, 
                               const cocos2d::Vec2 &point = cocos2d::Vec2(0.5f, 0.5f));

    ItemList &addComponent(std::string parent, 
                           std::string name, 
                           cocos2d::Node *component, 
                           const cocos2d::Vec2 &position = cocos2d::Vec2::ZERO, 
                           const cocos2d::Vec2 &point = cocos2d::Vec2(0.5f, 0.5f));

    ItemList &addChild(std::string name, cocos2d::Node *child);

    ItemList &setPosition(std::string name, const cocos2d::Vec2 &position);

    ItemList &setAnchorPoint(std::string name, const cocos2d::Vec2 &point);

    cocos2d::Node *getComponent(std::string name);

    cocos2d::Node *mainComponent();

};

#endif//__ITEM_LIST_H__