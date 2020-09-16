#include <iostream>
#include "Scene1.h"
#include "SimpleAudioEngine.h"
#include "utils/OptionalObject.h"

USING_NS_CC;

Scene *Scene1::createScene() 
{
    return Scene1::create();
}

static void problemLoading(const char *filename)
{
    std::cerr << "Error while loading: " << filename << std::endl;
    std::cerr << "Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp" << std::endl;
}

bool Scene1::init()
{
    /*
    chama o init da classe base 
    e verifica se ocorrera algum problema.
    caso ocorra retorna false.
    */
    if (!Scene::init())
        return false;

    /*
    pega a instancia unica do objeto Director
    Objeto responsavel em gerenciar o jogo.
    */
    auto director = Director::getInstance();

    //pega o tamanho da area visivel da tela
    auto visibleSize = director->getVisibleSize();
    //pega o ponto inicial da tela (normalmente canto inferior esquerdo)
    auto origin = director->getVisibleOrigin();

    //cria o botão de sair do menu
    auto closeItem = MenuItemImage::create("CloseNormal.png", 
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(Scene1::menuCloseCallback, this));

    //verifica se o botão eh invalido
    if (!closeItem || closeItem->getContentSize().width <= 0 || closeItem->getContentSize().height <= 0) 
    {
        //mostra o erro ao carregar a imagem
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else 
    {
        //posiciona o objeto com relação a origem e o tamanho da area visivel da tela tela
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    //cria o menu, adicionando o botão de sair ao menu
    auto menu = Menu::create(closeItem, nullptr);
    //posiciona o menu
    menu->setPosition(Vec2::ZERO);
    //adiciona o meno a arvore de renderização
    this->addChild(menu, 1);

    /*
    Teste da classe OptionalObject
    baseda na classe Optional do java 
    serve para evitar as verificações com nullptr.
    */
    auto optionalLabel = OptionalObject<Label>::create(Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24));
    
    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    /*if (!label)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }*/

    //se existior o objeto
    if (optionalLabel.isPresent())
    {
        //recupera a label
        auto label = optionalLabel.get();
        //posiciona com relaçao a origem e o tamanho da area visivel da tela
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));
        //adiciona a arvore de renderização
        this->addChild(label, 1);
    }
    //caso contrario se for nulo
    else
    {
        //mostra o erro ao carregar o arquivo
        problemLoading("'fonts/Marker Felt.ttf'");
    }

    //cria o sprite
    auto sprite = Sprite::create("HelloWorld.png");

    //verifica se o sprite eh invalido
    if(!sprite)
    {
        //mostra o erro ao carregar o sprite
        problemLoading("'HelloWorld.png'");
    }
    //caso contrario
    else 
    {
        //posiciona o sprite no centro da tela
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        //adiciona a arvore de renderização
        this->addChild(sprite, 0);
    }

    return true;
}

void Scene1::update(float delta)
{
    Scene::update(delta);
}

void Scene1::menuCloseCallback(Ref *sender)
{
    Director::getInstance()->end();
}