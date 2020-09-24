#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "Base/SceneBase.h"

class GameScene : public SceneBase
{
private:
    void close();

protected:
    virtual void config();
    
public:
    GameScene();
    ~GameScene();

    CREATE_FUNC(GameScene);

    static cocos2d::Scene* createScene();
};

#endif//__GAME_SCENE_H__