#ifndef __SCENE_BASE_H__
#define __SCENE_BASE_H__

#include "cocos2d.h"
#include "FairyGUI.h"

class Background;
/**
 * SceneBase
 * 
 * Classe base para todas as cenas do jogo.
 * 
 * Todas as classes do jogo devem herdar desta classe, pois ela
 * possui algumas configurações iniciais.
 * 
 * Ao herda-la, a cena de implementar o metodo config para suas
 * configurações proprias.
 * 
 * Atributos:
 *   -> groot do tipo fairygui::GRoot: Atributo container de 
 *         Packages;
 *   -> view do tipo fairygui::GComponent: Package de components;
 *   -> background do tipo Background: Representa o plano de fundo.
 */
class SceneBase : public cocos2d::Scene
{
protected:
    /**
     * Atributo container que armazenara os Packages
     * necessarios para a construção da cena 
     * */ 
    fairygui::GRoot *groot;
    /**
     * Atributo que eh o Package de components
     * da cena. Exemplo: textos, botões, imagens, etc.
     * */
    fairygui::GComponent *view;
    /**
     * Atributo para o fundo de tela da cena.
     * Padrão para todas as cenas.
     * */
    Background *background;
    
protected:
    /**
     * Metodo de configuração expecifica de uma cena.
     * A sua chamado acontece dentro do metodo Init.
     * */
    virtual void config() = 0;

public:
    /**
     * Contrutor Padrão.
     * */
    SceneBase();
    /**
     * Destrutor.
     * */
    virtual ~SceneBase();
    /**
     * Metodo de inicialização.
     * Padrão para todas as cenas.
     * */
    virtual bool init() final;
};

#endif//__SCENE_BASE_H__ 