/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <iostream>
#include <time.h>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void HelloWorld::addMonster(const float secs) 
{
    auto monster = Sprite::create("SimpleGameResources/monster.png");

    if (monster == nullptr)
    {
        problemLoading("'player.png'");
    }
    else
    {
        auto monsterContentSize = monster->getContentSize();
        auto selfContentSize = this->getContentSize();
        int minY = monsterContentSize.height / 2;
        int maxY = selfContentSize.height - monsterContentSize.height / 2;
        int rangeY = maxY - minY;
        int randomY = (rand() % rangeY) + minY;

        monster->setPosition(Vec2(selfContentSize.width + monsterContentSize.width/2, 
                                 randomY));
        this->addChild(monster);

        int minDuration = 2;
        int maxDuration = 4;
        int rangeDuration = maxDuration - minDuration;
        int randomDuration = (rand() % rangeDuration) + minDuration;

        //cria a ação do movimento do monstro
        auto actionMove = MoveTo::create(randomDuration, Vec2(-monsterContentSize.width/2, randomY));
        //crea a ação de remover, para remover o sprite da arvore quando necessario
        auto actionRemove = RemoveSelf::create();
        //executa uma sequencia de ações de cada vez
        monster->runAction(Sequence::create(actionMove, actionRemove, nullptr));
    }

}

bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
    //exemplo de como obter o objeto player
    //auto node = unused_event->getCurrentTarget();

    //recupera a posição do toque na tela
    auto touchLocation = touch->getLocation();
    //calcula a distancia do toque com relação ao player para a direção do tiro
    auto offset = touchLocation - player->getPosition();

    //se o valor de x for menor que zero
    //o player estara atirando para traz
    if (offset.x < 0)
        return true;

    //cria um projetio
    auto projectile = Sprite::create("SimpleGameResources/projectile.png");
    //posiciona na posição do jogador
    projectile->setPosition(player->getPosition());
    //adiciona na arvore de renderização
    this->addChild(projectile);

    //normaliza o vetor de de direção
    offset.normalize();
    //multiplica por 1000 para obter um valor fora da tela
    auto shootAmount = offset * 1000;
    
    auto realDest = shootAmount + projectile->getPosition();
    //cria a ação para mover o projetil por 2 segundos
    auto actionMove = MoveTo::create(2.0f, realDest);
    //cria a ação para remover o sprite
    auto actionRemove = RemoveSelf::create();
    //executa a sequencia de ações
    projectile->runAction(Sequence::create(actionMove, actionRemove, nullptr));

    return true;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

/***********************************************************/
    //if (!Layer::init())
    //    return false;

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    //plano de fundo
    auto background = DrawNode::create();
    background->drawSolidRect(origin, visibleSize, Color4F(0.6,0.6,0.6,1.0));
    this->addChild(background);

    player = Sprite::create("SimpleGameResources/player.png");
    if (player == nullptr)
    {
        problemLoading("'player.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        player->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height*0.5));

        // add the sprite as a child to this layer
        this->addChild(player);
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    //chama o metodo addMoster a cada 1,5 segundos
    this->schedule(schedule_selector(HelloWorld::addMonster), 1.5);
    //chama o metodo de retorno uma vez para cada evento de toque
    auto eventListener = EventListenerTouchOneByOne::create();
    //chama ao toque na tela
    eventListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, player);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
