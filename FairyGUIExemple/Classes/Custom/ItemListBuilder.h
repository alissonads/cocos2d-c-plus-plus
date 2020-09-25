#ifndef __ITENS_LIST_BUILDER_H__
#define __ITENS_LIST_BUILDER_H__

#include "FairyGUI.h"
#include <string>

class ItemListBuilder
{
private:
    fairygui::GComponent *item;

private:
    ItemListBuilder();

public:
    static ItemListBuilder builder(const std::string &pkgName, 
                                   const std::string &resName);
    
    ItemListBuilder &setText(const std::string &name, 
                             const std::string &text);

    fairygui::GComponent *create() const;
};

#endif//__ITENS_LIST_BUILDER_H__