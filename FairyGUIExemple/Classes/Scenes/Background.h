#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"

/**
 * Classe responsavel pelo plano de fundo da tela.
 * 
 * Atributo:
 *   -> node do tipo cocos2d::Node: representa o
 *          no na arvore principal.
 * */
class Background
{
    private:
        /**
         * NÓ que sera adiocionado na Arvore principal
         * */
        cocos2d::Node *node;

    private:
        /**
         * Metodo auxiliar para adicionar o NÓ
         * no atributo node
         * */
        void setNode(cocos2d::Node *node);

        /**
         * Construtor Padrão.
         * */
        Background();
        
    public:
        /**
         * Destrutor
         * */
        ~Background();
         
        /**
         * Método statico de construção de um plano de fundo com cor solida. Constroi atraves de  um Color4F.
         * Parametros:
         *   -> color do tipo cocos2d::Color4F
         *   -> size do tipo cocos2d::Vec2: representa o tamanho do plano de fundo.
         *          obs(por padrão desenha em toda a parte visivel da tela).
         * 
         * Retorno:
         *   -> Retorna um pontiro para um objeto Background. 
         * */
        static Background *createBgSolidColor(const cocos2d::Color4F &color, const cocos2d::Vec2 &size = cocos2d::Vec2());

        /**
         * Método statico de construção de um plano de fundo com cor solida. Constroi atraves de 
         * 3 inteiros que representão R, G, B de 0 a 255.
         * Parametros:
         *   -> r do tipo int: representa o canal Red
         *   -> g do tipo int: representa o canal Green
         *   -> b do tipo int: representa o canal Blue
         *   -> size do tipo cocos2d::Vec2: representa o tamanho do plano de fundo.
         *          obs(por padrão desenha em toda a parte visivel da tela).
         * 
         * Retorno:
         *   -> Retorna um pontiro para um objeto Background. 
         * */
        static Background *createBgSolidColorI(const int r, const int g, const int b, const cocos2d::Vec2 &size = cocos2d::Vec2());

        /**
         * Método statico de construção de um plano de fundo com cor solida. Constroi atraves de 
         * 3 inteiros que representão R, G, B de 0.0f a 1.0f.
         * Parametros:
         *   -> r do tipo float: representa o canal Red
         *   -> g do tipo float: representa o canal Green
         *   -> b do tipo float: representa o canal Blue
         *   -> size do tipo cocos2d::Vec2: representa o tamanho do plano de fundo.
         *          obs(por padrão desenha em toda a parte visivel da tela).
         * 
         * Retorno:
         *   -> Retorna um pontiro para um objeto Background. 
         * */
        static Background *createBgSolidColorF(const float r, const float g, const float b, const cocos2d::Vec2 &size = cocos2d::Vec2());

        /**
         * Método statico de construção de um plano de fundo com imagem.
         * Parametros:
         *   -> fileName do tipo char*: uma cadeia de caracteres com o caminho da imagem
         *         que será carregada para o plano de fundo.
         * 
         * Retorno:
         *   -> Retorna um pontiro para um objeto Background. 
         * */
        static Background *createBgWithImage(const char *fileName, const cocos2d::Vec2 &size = cocos2d::Vec2());

        /**
         * Método auxiliar para o retorno do NÓ para a arvore.
         * */
        cocos2d::Node *getNode() const;

        Background &setChild(cocos2d::Node *child);
};

#endif//__BACKGROUND_H__