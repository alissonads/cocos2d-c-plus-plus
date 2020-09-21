#include "ItemList.h"

USING_NS_CC;

ItemList::ItemList() :
          component(nullptr)
{}

/*ItemList::ItemList build()
{
    return ItemList();
}*/

ItemList &ItemList::setComponent(Node *component)
{
    this->component = component;

    return (*this);
}

ItemList &ItemList::addChild(Node *child)
{
    component->addChild(child);

    return (*this);
}

ItemList &ItemList::setPosition(const Vec2 &position)
{
    component->setPosition(position);

    return (*this);
}

ItemList &ItemList::setAnchorPoint(const Vec2 &point)
{
    component->setAnchorPoint(point);

    return (*this);
}

cocos2d::Node *ItemList::create() const
{
    return component;
}