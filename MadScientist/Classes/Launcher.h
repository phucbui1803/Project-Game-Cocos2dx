#ifndef __LAUNCHER_H__
#define __LAUNCHER_H__

#include "cocos2d.h"

class Launcher : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(Launcher);
};

#endif // __LAUNCHER_H__
