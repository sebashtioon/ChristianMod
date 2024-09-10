// ChristianModLayer.hpp
#pragma once
#include <cocos2d.h>
#include <Geode/Geode.hpp>
#include <Geode/binding/FLAlertLayer.hpp>
#include <Geode/ui/MDTextArea.hpp>

using namespace geode::prelude;
using namespace cocos2d;

class ChristianModLayer : public CCLayer {
public:
    // Initializes the layer
    bool init() override;

    // Button press handlers
    void onInfoButton(CCObject* sender);
    void onPrayButtonPressed(CCObject* sender);
    void onHowAreYouFeelingTodayButton(CCObject* sender);
    void onClose(CCObject* sender);

    // Static create function to construct the layer
    static ChristianModLayer* create();
};
