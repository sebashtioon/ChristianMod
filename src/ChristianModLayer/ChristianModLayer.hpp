#pragma once

#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <Geode/Geode.hpp>
#include <cocos2d.h>
#include <Geode/Enums.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/modify/CCLayer.hpp>
#include <Geode/modify/CCScene.hpp>
#include <Geode/binding/FLAlertLayer.hpp>
#include <Geode/ui/Popup.hpp>
#include <Geode/ui/MDTextArea.hpp>
#include <Geode/binding/TextArea.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include <Geode/cocos/actions/CCActionInstant.h>
#include <Geode/cocos/actions/CCActionInterval.h>
#include <Geode/cocos/base_nodes/CCNode.h>

using namespace geode::prelude;

class ChristianModLayer : public CCLayer {
protected:
    virtual bool init();
    virtual void onKeyBackClicked(); // when escape is pressed

public:
    static ChristianModLayer* create(); // to create the layer

    void onInfoButton(CCObject* sender); // The info button
    void onPrayButtonPressed(CCObject* sender); // Pray button under verse of the day
    void onHowAreYouFeelingTodayButton(CCObject* sender); // How are you feeling today button
    void onClose(CCObject* sender); // Close button
    
};