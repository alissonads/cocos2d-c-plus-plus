#include "Background.h"

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
    // Recupera a instancia de Director
    auto director = Director::getInstance();
    // Cria uma instancia para Background
    auto background = new Background();
    // Recupera o inicio (0, 0) da parte visivel da tela.
    auto origin = director->getVisibleOrigin();
    // Recupera o tamanho da tela.
    auto winSize = (size.getLength() < 1.0f) ? director->getWinSize() : size;
    // Cria uma instancia de um DrawNode
    auto aux = DrawNode::create();
    // Adiciona as configurações para desenhar o background
    aux->drawSolidRect(origin, winSize, color);
    // Adiciona o NÓ à instancia do background
    background->setNode(aux);

    //retorna a instancia do Background
    return background;
}

Background *Background::createBgSolidColorI(const int r, const int g, const int b, const Vec2 &size) 
{
    // retorna o metodo createBgSolidColor configurando os 3 inteiros
    // para Color4F e dividindo por 255 para ficar no intervalo de 0.0f a 1.0f
    return createBgSolidColor(Color4F(r, g, b, 255)/255, size);
}

Background *Background::createBgSolidColorF(const float r, const float g, const float b, const Vec2 &size)
{
    // retorna o metodo createBgSolidColor configurando os 3 floats
    // para Color4F 
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
