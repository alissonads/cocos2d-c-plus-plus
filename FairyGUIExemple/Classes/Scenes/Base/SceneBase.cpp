#include "SceneBase.h"
#include "../Background.h"

USING_NS_CC;
USING_NS_FGUI;

SceneBase::SceneBase() :
            groot(nullptr),
            view(nullptr),
            background(nullptr)
{}

SceneBase::~SceneBase() 
{
    CC_SAFE_RELEASE(groot);
    // se o atributo for diferente de nullptr
    if (background)
    {
        // deleta o atributo
        delete background;
        background = nullptr;
    }
}

bool SceneBase::init()
{
    // Inicializa a cena base.
    // E verifica se returna true.
    if (Scene::init())
    {
        // Cria o background com uma cor solida
        background = Background::createBgSolidColorI(36,43,46);
        // Adiciona o no do background a arvore principal
        this->addChild(background->getNode());

        // cria o container de Packages
        groot = GRoot::create(this);
        groot->retain();

        // Chama a configuração expecialiszada 
        // das cenas que implementar o metodo
        // config
        config();

        return true;
    }

    // Se o retorno for false
    return false;
}