#ifndef __ESPECIALIST_LOADER_H__
#define __ESPECIALIST_LOADER_H__

#include "FairyGUI.h"
#include "network/CCDownloader.h"

class EspecialistLoader : public fairygui::GLoader
{
private:
    std::unique_ptr<cocos2d::network::Downloader> downloader;

protected:
    EspecialistLoader();
    
    virtual void loadExternal() override;
    virtual void freeExternal(cocos2d::SpriteFrame* spriteFrame) override;
};

#endif//__ESPECIALIST_LOADER_H__