#include "EspecialistLoader.h"

USING_NS_CC;
USING_NS_FGUI;

EspecialistLoader::EspecialistLoader()
{
    downloader.reset(new network::Downloader());
}

void EspecialistLoader::loadExternal()
{
    auto url = getURL();

    downloader->onDataTaskSuccess = [this](const cocos2d::network::DownloadTask& task,
                                           std::vector<unsigned char>& data) 
    {
        Image img;

        if (!img.initWithImageData(data.data(), data.size()))
            return;

        auto texture = new Texture2D();

        if (!texture->initWithImage(&img))
            return;

        auto sprite = SpriteFrame::createWithTexture(texture, Rect(Vec2::ZERO, texture->getContentSize()));

        onExternalLoadSuccess(sprite);

        CC_SAFE_RELEASE(texture);
    };  

    downloader->createDownloadDataTask(url);
}

void EspecialistLoader::freeExternal(SpriteFrame* spriteFrame)
{

}

/*void GLoader::loadExternal()
{
    auto tex = Director::getInstance()->getTextureCache()->addImage(_url);
    if (tex)
    {
        auto sf = SpriteFrame::createWithTexture(tex, Rect(Vec2::ZERO, tex->getContentSize()));
        onExternalLoadSuccess(sf);
    }
    else
        onExternalLoadFailed();
}

void GLoader::freeExternal(cocos2d::SpriteFrame* spriteFrame)
{
}

void GLoader::onExternalLoadSuccess(cocos2d::SpriteFrame* spriteFrame)
{
    _contentStatus = 4;
    _content->setSpriteFrame(spriteFrame);
    Size sz = spriteFrame->getRectInPixels().size;
    _contentSourceSize.width = sz.width;
    _contentSourceSize.height = sz.height;
    updateLayout();
}*/