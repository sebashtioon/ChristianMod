#pragma once
#include <cocos2d.h>
#include "ChristianModLayer.hpp"

class ChristianModScene : public cocos2d::CCScene {
public:
    bool init() override;

    static ChristianModScene* create();
};
