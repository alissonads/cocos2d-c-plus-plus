#include "ItemListBuilder.h"

USING_NS_FGUI;

ItemListBuilder::ItemListBuilder() :
                    item(nullptr)
{}

ItemListBuilder ItemListBuilder::builder(const std::string &pkgName, 
                                         const std::string &resName)
{
    auto itenListBuilder = ItemListBuilder();
    itenListBuilder.item = UIPackage::createObject(pkgName, pkgName)->as<GComponent>();

    return itenListBuilder; 
}
    
ItemListBuilder &ItemListBuilder::setText(const std::string &name, 
                                          const std::string &text)
{
    auto obj = item->getChild(name);
    obj->setText(text);

    return (*this);
}

fairygui::GComponent *ItemListBuilder::create() const
{
    return item;
}