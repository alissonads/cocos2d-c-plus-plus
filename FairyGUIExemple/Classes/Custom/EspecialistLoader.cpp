#include "EspecialistLoader.h"

USING_NS_CC;
USING_NS_FGUI;

EspecialistLoader::EspecialistLoader() : 
                    GLoader(),
                    texture(nullptr)
{
    downloader.reset(new network::Downloader());
}

void EspecialistLoader::loadExternal()
{
    //GLoader::loadExternal();
    auto url = getURL();

    downloader->onDataTaskSuccess = [this](const cocos2d::network::DownloadTask& task,
                                           std::vector<unsigned char>& data) 
    {
        Image img;

        if (!img.initWithImageData(data.data(), data.size()))
            return;

        auto tex = new Texture2D();

        if (tex->initWithImage(&img))
        {
            auto sprite = SpriteFrame::createWithTexture(tex,
                                                         Rect(Vec2::ZERO,
                                                              tex->getContentSize()));
            onExternalLoadSuccess(sprite);
        }
        else
        {
            onExternalLoadFailed();
            CC_SAFE_RELEASE(texture);
        }
    };  

    downloader->createDownloadDataTask(url);

    /*if (texture)
    {
        auto sprite = SpriteFrame::createWithTexture(texture, 
                                                     Rect(Vec2::ZERO, 
                                                          texture->getContentSize()));
        onExternalLoadSuccess(sprite);
    }
    else
    {
        onExternalLoadFailed();
    }*/
}

void EspecialistLoader::freeExternal(SpriteFrame* spriteFrame)
{
    GLoader::freeExternal(spriteFrame);
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