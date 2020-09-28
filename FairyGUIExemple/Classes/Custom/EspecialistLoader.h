#ifndef __ESPECIALIST_LOADER_H__
#define __ESPECIALIST_LOADER_H__

#include "FairyGUI.h"
#include "network/CCDownloader.h"


class EspecialistLoader : public fairygui::GLoader
{
private:
    std::unique_ptr<cocos2d::network::Downloader> downloader;
    cocos2d::Texture2D *texture;

protected:
    virtual void loadExternal() override;
    virtual void freeExternal(cocos2d::SpriteFrame* spriteFrame) override;

public:
    EspecialistLoader();

    CREATE_FUNC(EspecialistLoader);
};

#endif//__ESPECIALIST_LOADER_H__