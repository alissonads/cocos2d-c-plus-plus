#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "Base/SceneBase.h"
#include "Custom/FileRequestListener.h"
#include <string>

class CustomFileRequest;

/**
 * Classe da Cena que representa o Menu do Jogo.
 * 
 * Extende da Classe SceneBase
 * Implementa a FileRequestListener para se tornar ouvinte de uma
 * requisiçao feita ao servidor pela classe CustomFileRequest.
 *  
 * Atrinutos:
 *   -> request do tipo CustomFileRequest: é um ponteiro para
 *          um CustomFileRequest. 
 * */
class MenuScene : public SceneBase,
                  public FileRequestListener
{
private:
    /**
     * Objeto que fará a requisição ao servidor.
     * */
    CustomFileRequest *request;

    /**
     * Método que registrará o comando de 
     * saida da cena
     * */
    void close();

protected:
    /**
     * Método extendido da Classe SceneBase.
     * Utilizado para as configurações adicionais
     * da MenuScene
     * */
    virtual void config();

    /**
     * Método de auxiliar para criar e configurar um componente
     * de uma GList do FairyGUI.
     * 
     * Parametros:
     *   -> imageUrl do tipo std::string: representa a url da 
     *        imagem recebida da consulta ao servidor;
     *   -> musicName do tipo std::string: representa o nome
     *        da musica recebida da consulta ao servidor;
     *   -> artistName do tipo std::string: representa o nome
     *        do artista recebida da consulta ao servidor;
     * */
    void addCompentList(const std::string &imageUrl,
                        const std::string &musicName,
                        const std::string &artistName);
public:
    /**
     * Menu Padrão
     * */
    MenuScene();
    /**
     * Destrutor
     * */
    ~MenuScene();

    /**
     * define um função estatica para 
     * criação da MenuScene.
     * */
    CREATE_FUNC(MenuScene);

    static cocos2d::Scene* createScene();

    /**
     * Método implementado da Classe (Interface) FileRequestListener
     * Para aplicar os dados recebidos pelo servidor.
     * 
     * Parametros:
     *   -> buffer do tipo std::vector<char>: é a representação dos dados
     *       que vem (de forma bruta) da requisição ao servidor, para ser
     *       processado.
     * 
     * Obs: Ela é chamada dentro do método toSend da classe CustomFileRequest.
     * */
    virtual void applyData(const std::vector<char> &buffer);
};

#endif//__MENU_SCENE_H__