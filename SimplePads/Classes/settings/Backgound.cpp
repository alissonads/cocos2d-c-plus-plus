#include "Backgound.h"

USING_NS_CC;

Background::Background() :
        node(nullptr)
{}

Background::~Background() 
{
    if (node)
    {
        delete node;
        node = nullptr;
    }
}

Background *Background::createBgSolidColor(const Color4F &color, const Vec2 &size)
{
    auto director = Director::getInstance();
    auto background = new Background();
    auto origin = director->getVisibleOrigin();
    auto winSize = (size.getLength() < 1.0f) ? director->getWinSize() : size;
    auto aux = DrawNode::create();
    aux->drawSolidRect(origin, winSize, color);
    background->setNode(aux);
    
    return background;
}

Background *Background::createBgSolidColorI(const int r, const int g, const int b, const Vec2 &size) 
{
    return createBgSolidColor(Color4F(r, g, b, 255)/255, size);
}

Background *Background::createBgSolidColorF(const float r, const float g, const float b, const Vec2 &size)
{
    return createBgSolidColor(Color4F(r, g, b, 1.0f), size);
}

Background *Background::createBgWithImage(const char *fileName, const Vec2 &size) 
{
    return nullptr;
}

cocos2d::Node *Background::getNode() const
{
    return node;
}

Background &Background::setChild(Node *child)
{
    this->node = node;

    return (*this);
}

void Background::setNode(Node *node)
{
    this->node = node;
}
