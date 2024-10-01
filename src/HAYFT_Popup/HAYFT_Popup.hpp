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
#include "../ChristianModLayer/ChristianModLayer.hpp"


// specify parameters for the setup function in the Popup<...> template
class HAYFT_Popup : public geode::Popup<std::string const&> {
protected:
    virtual bool setup(std::string const& value) override;

public:
    static HAYFT_Popup* create(std::string const& text);
    void disableHayftButtonsMenu(CCNode* node);
    void updateUIWithTween(CCNode* node);
    void changeText(CCNode* sender);
    void displayMessage(const std::string& message);
    void displayModuleInfo(const std::string& message);
    void onhayftPopupInfoBtn(CCObject* sender);

    // all the button handlers
    void onHappyBtn(CCObject* sender);
    void onCalmBtn(CCObject* sender);
    void onNervousBtn(CCObject* sender);
    void onAngryBtn(CCObject* sender);
    void onGuiltyBtn(CCObject* sender);
    void onSadBtn(CCObject* sender);
    void onBlessedBtn(CCObject* sender);
    void onFaithfulBtn(CCObject* sender);
    void onFearfulBtn(CCObject* sender);
    void onThankfulBtn(CCObject* sender);
    void onExcitedBtn(CCObject* sender);
    void onWeakBtn(CCObject* sender);
};
