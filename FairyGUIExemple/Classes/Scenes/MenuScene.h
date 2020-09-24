#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "Base/SceneBase.h"
#include "Custom/FileRequestListener.h"

class CustomFileRequest;

class MenuScene : public SceneBase,
                  public FileRequestListener
{
private:
    CustomFileRequest *request;

    void close();

protected:
    virtual void config();

public:
    MenuScene();
    ~MenuScene();

    CREATE_FUNC(MenuScene);

    static cocos2d::Scene* createScene();

    virtual void update(rapidjson::Document &document);
};

#endif//__MENU_SCENE_H__