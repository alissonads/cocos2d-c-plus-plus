#include "ItemList.h"

USING_NS_CC;

ItemList::ItemList() :
          components()
{}

ItemList::~ItemList()
{
    /*for (auto item : components)
    {
        delete item.second;
    }*/

    components.clear();
}

ItemList &ItemList::setMainComponent(Node *component, 
                                     const Vec2 &position, 
                                     const Vec2 &point)
{
    return addComponent("", "main", component, position, point);
}

ItemList &ItemList::addComponent(std::string parent,     
                                 std::string name, 
                                 Node *component, 
                                 const Vec2 &position, 
                                 const Vec2 &point)

{
    if (name != "" && components.find(name) == components.end())
    {
        components[name] = component;
        component->setAnchorPoint(point);
        component->setPosition(position);
        components[name]->getChildByName(name);
    }
    
    addChild(parent, component);

    return (*this);
}

ItemList &ItemList::setPosition(std::string name, const Vec2 &position)
{
    if (name != "" && components.find(name) != components.end())
    {
        components[name]->setPosition(position);
    }

    return (*this);
}

ItemList &ItemList::addChild(std::string name, Node *child)
{
    if (name != "" && components.find(name) != components.end())
    {
        components[name]->addChild(child);
    }

    return (*this);
}

ItemList &ItemList::setAnchorPoint(std::string name, const Vec2 &point)
{
    if (name != "" && components.find(name) != components.end())
    {
        components[name]->setAnchorPoint(point);
    }

    return (*this);
}

Node *ItemList::getComponent(std::string name)
{
    if (name != "" && components.find(name) != components.end())
        return components[name];

    return nullptr;
}

Node *ItemList::mainComponent()
{
    return components["main"];
}