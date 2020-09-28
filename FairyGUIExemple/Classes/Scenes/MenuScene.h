#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "Base/SceneBase.h"
#include "Custom/FileRequestListener.h"
#include <string>

class CustomFileRequest;

class MenuScene : public SceneBase,
                  public FileRequestListener
{
private:
    CustomFileRequest *request;

    void close();

protected:
    virtual void config();

    void addCompentList(const std::string &imageUrl,
                        const std::string &musicName,
                        const std::string &artistName);
public:
    MenuScene();
    ~MenuScene();

    CREATE_FUNC(MenuScene);

    static cocos2d::Scene* createScene();

    virtual void applyData(const std::vector<char> &buffer);
};

#endif//__MENU_SCENE_H__