#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "Base/SceneBase.h"
#include <string>

class GameScene : public SceneBase
{
private:
    std::string kitName;

    void close();

protected:
    virtual void config();
    
public:
    GameScene();
    ~GameScene();

    CREATE_FUNC(GameScene);

    static cocos2d::Scene* createScene();

    void setKitName(const std::string &kitName);

    std::string getKitName() const;
};

#endif//__GAME_SCENE_H__