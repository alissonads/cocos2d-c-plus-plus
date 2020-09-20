#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"

class Background
{
    private:
        cocos2d::Node *node;

    private:
        void setNode(cocos2d::Node *node);

        Background();
        
    public:
        ~Background();

        static Background *createBgSolidColor(const cocos2d::Color4F &color, const cocos2d::Vec2 &size = cocos2d::Vec2());

        static Background *createBgSolidColorI(const int r, const int g, const int b, const cocos2d::Vec2 &size = cocos2d::Vec2());

        static Background *createBgSolidColorF(const float r, const float g, const float b, const cocos2d::Vec2 &size = cocos2d::Vec2());

        static Background *createBgWithImage(const char *fileName, const cocos2d::Vec2 &size = cocos2d::Vec2());

        cocos2d::Node *getNode() const;

        Background &setChild(cocos2d::Node *child);
};

#endif//__BACKGROUND_H__