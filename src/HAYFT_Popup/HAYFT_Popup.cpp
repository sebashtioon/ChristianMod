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
#include "HAYFT_Popup.hpp"


bool HAYFT_Popup::setup(std::string const& value) {
    auto winSize = CCDirector::sharedDirector()->getWinSize();

/* ---------------------------------- Title --------------------------------- */
    auto title = CCLabelBMFont::create("How are you feeling today?", "bigFont.fnt");
    title->setPosition({290.f, 264.f});
    title->setScale(0.675);
    this->addChild(title);
    title->setID("cmod-hayft-popup-title");
/* --------------------------- HAYFT Buttons menu --------------------------- */
    auto hayftButtonsMenu = CCMenu::create();
    hayftButtonsMenu->setPosition({291.5f, 160.f});
    this->addChild(hayftButtonsMenu);
    hayftButtonsMenu->setID("cmod-hayft-buttons-menu");
    hayftButtonsMenu->setZOrder(1);

/* ----------------------------- hayftForeground ---------------------------- */
    auto hayftForeground = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", { .0f, .0f, 80.0f, 80.0f });
    hayftForeground->setContentSize({ 153.f, 95.f });
    hayftForeground->setAnchorPoint({ .5f, 1.f });
    hayftForeground->setColor({ 123, 60, 31 });
    hayftForeground->setScale(2.05f);
    hayftForeground->setPosition({284.5f, 245.f});
    hayftForeground->setID("cmod-hayft-foreground");
/* -------------------------- hayftPopup_InfoButton ------------------------- */
    auto hayftPopup_InfoButtonSpr = CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
    hayftPopup_InfoButtonSpr->setScale(1.025f);

    auto hayftPopup_InfoButton = CCMenuItemSpriteExtra::create(
        hayftPopup_InfoButtonSpr,
        this,
        menu_selector(HAYFT_Popup::onhayftPopupInfoBtn)
    );
    hayftPopup_InfoButton->setID("info-button");
    hayftPopup_InfoButton->setPosition({177.f, 116.f});
/* -------------------------------------------------------------------------- */
/*                       Create HAYFT Buttons (feelings)                      */
/* -------------------------------------------------------------------------- */
/* ---------------------------------- Happy --------------------------------- */
    auto happyBtnSprite = CCSprite::create("happy-complete.png"_spr);
    happyBtnSprite->setScale(0.1f);

    auto happyBtn = CCMenuItemSpriteExtra::create(
        happyBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onHappyBtn)
        );
    happyBtn->setID("cmod-happy-btn");
    happyBtn->setPosition({-100.f, 47.f});

/* ---------------------------------- Calm ---------------------------------- */
    auto calmBtnSprite = CCSprite::create("calm-complete.png"_spr);
    calmBtnSprite->setScale(0.1f);
    auto calmBtn = CCMenuItemSpriteExtra::create(
        calmBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onCalmBtn)
        );
    calmBtn->setID("cmod-calm-btn");
    calmBtn->setPosition({-40.f, 47.f});
/* --------------------------------- Nervous -------------------------------- */
    auto nervousBtnSprite = CCSprite::create("nervous-complete.png"_spr);
    nervousBtnSprite->setScale(0.105f);
    auto nervousBtn = CCMenuItemSpriteExtra::create(
        nervousBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onNervousBtn)
        );
    nervousBtn->setID("cmod-nervous-btn");
    nervousBtn->setPosition({20.f, 47.f});
/* ---------------------------------- Angry --------------------------------- */
    auto angryBtnSprite = CCSprite::create("angry-complete.png"_spr);
    angryBtnSprite->setScale(0.105f);
    auto angryBtn = CCMenuItemSpriteExtra::create(
        angryBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onAngryBtn)
        );
    angryBtn->setID("cmod-angry-btn");
    angryBtn->setPosition({80.f, 47.f});
/* --------------------------------- Guilty --------------------------------- */
    auto guiltyBtnSprite = CCSprite::create("guilty-complete.png"_spr);
    guiltyBtnSprite->setScale(0.105f);
    auto guiltyBtn = CCMenuItemSpriteExtra::create(
        guiltyBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onGuiltyBtn)
        );
    guiltyBtn->setID("cmod-guilty-btn");
    guiltyBtn->setPosition({-100.f, -14.f});
/* ----------------------------------- Sad ---------------------------------- */
    auto sadBtnSprite = CCSprite::create("sad-complete.png"_spr);
    sadBtnSprite->setScale(0.105f);
    auto sadBtn = CCMenuItemSpriteExtra::create(
        sadBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onSadBtn)
        );
    sadBtn->setID("cmod-sad-btn");
    sadBtn->setPosition({-40.f, -14.f});
/* --------------------------------- Blessed -------------------------------- */
    auto blessedBtnSprite = CCSprite::create("blessed-complete.png"_spr);
    blessedBtnSprite->setScale(0.368f);
    auto blessedBtn = CCMenuItemSpriteExtra::create(
        blessedBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onBlessedBtn)
        );
    blessedBtn->setID("cmod-blessed-btn");
    blessedBtn->setPosition({20.f, -14.f});
/* -------------------------------- Faithful -------------------------------- */
    auto faithfulBtnSprite = CCSprite::create("faithful-complete.png"_spr);
    faithfulBtnSprite->setScale(0.335f);
    auto faithfulBtn = CCMenuItemSpriteExtra::create(
        faithfulBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onFaithfulBtn)
        );
    faithfulBtn->setID("cmod-faithful-btn");
    faithfulBtn->setPosition({80.f, -14.f});
/* --------------------------------- Fearful -------------------------------- */
    auto fearfulBtnSprite = CCSprite::create("fearful-complete.png"_spr);
    fearfulBtnSprite->setScale(0.335f);
    auto fearfulBtn = CCMenuItemSpriteExtra::create(
        fearfulBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onFearfulBtn)
        );
    fearfulBtn->setID("cmod-fearful-btn");
    fearfulBtn->setPosition({-100.f, -75.f});
/* -------------------------------- Thankful -------------------------------- */
    auto thankfulBtnSprite = CCSprite::create("thankful-complete.png"_spr);
    thankfulBtnSprite->setScale(0.335f);
    auto thankfulBtn = CCMenuItemSpriteExtra::create(
        thankfulBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onThankfulBtn)
        );
    thankfulBtn->setID("cmod-thankful-btn");
    thankfulBtn->setPosition({-40.f, -75.f});
/* --------------------------------- Excited -------------------------------- */
    auto excitedBtnSprite = CCSprite::create("excited-complete.png"_spr);
    excitedBtnSprite->setScale(0.335f);
    auto excitedBtn = CCMenuItemSpriteExtra::create(
        excitedBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onExcitedBtn)
        );
    excitedBtn->setID("cmod-excited-btn");
    excitedBtn->setPosition({20.f, -75.f});
/* ---------------------------------- Weak ---------------------------------- */
    auto weakBtnSprite = CCSprite::create("weak-complete.png"_spr);
    weakBtnSprite->setScale(0.335f);
    auto weakBtn = CCMenuItemSpriteExtra::create(
        weakBtnSprite, 
        this, 
        menu_selector(HAYFT_Popup::onWeakBtn)
        );
    weakBtn->setID("cmod-weak-btn");
    weakBtn->setPosition({80.f, -75.f});
/* ------------------------ hayftPopup_InfoButtonMenu ----------------------- */
    auto hayftPopup_InfoButtonMenu = CCMenu::create();
    this->addChild(hayftPopup_InfoButtonMenu);
    hayftPopup_InfoButtonMenu->setID("cmod-hayft-popup-infobutton-menu");
/* ------------------- Add buttons to the hayftButtonsMenu ------------------ */

    hayftPopup_InfoButtonMenu->addChild(hayftPopup_InfoButton);

    hayftButtonsMenu->addChild(happyBtn);
    hayftButtonsMenu->addChild(calmBtn);
    hayftButtonsMenu->addChild(nervousBtn);
    hayftButtonsMenu->addChild(angryBtn);
    hayftButtonsMenu->addChild(guiltyBtn);
    hayftButtonsMenu->addChild(sadBtn);
    hayftButtonsMenu->addChild(blessedBtn);
    hayftButtonsMenu->addChild(faithfulBtn);
    hayftButtonsMenu->addChild(fearfulBtn);
    hayftButtonsMenu->addChild(thankfulBtn);
    hayftButtonsMenu->addChild(excitedBtn);
    hayftButtonsMenu->addChild(weakBtn);

/* ------------------------------ Popup config ------------------------------ */
    m_closeBtn->setPosition({-182.f, 115.f});
    m_bgSprite->setScale(1.55f);
/* ----------------------- Add children to hayft popup ---------------------- */
    this->addChild(hayftForeground);
/* ---------------------------------- Other --------------------------------- */
    return true;
}

HAYFT_Popup* HAYFT_Popup::create(std::string const& text) {
    auto ret = new HAYFT_Popup();
    if (ret->init(240.f, 160.f, text)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

void HAYFT_Popup::disableHayftButtonsMenu(CCNode* node) {
    auto hayftButtonsMenu = node->getChildByID("cmod-hayft-buttons-menu");
    if (hayftButtonsMenu) {
        auto menu = dynamic_cast<CCMenu*>(hayftButtonsMenu);
        if (menu) {
            menu->setEnabled(false);
        }
    }
}

void HAYFT_Popup::updateUIWithTween(CCNode* node) {
    // Disable the buttons menu
    disableHayftButtonsMenu(node);

    // Retrieve the buttons menu
    auto hayftButtonsMenu = node->getChildByID("cmod-hayft-buttons-menu");
    if (hayftButtonsMenu) {
        // Create fade out action
        auto fadeOut = CCFadeOut::create(1.0f); // 1 second to fade out

        // Create a sequence of fade out
        auto sequence = CCSequence::create(fadeOut, nullptr);

        // Run the sequence action on the buttons menu
        hayftButtonsMenu->runAction(sequence);
    }

    // Retrieve the title node
    auto hayftTTL = node->getChildByID("cmod-hayft-popup-title");
    auto ttl = dynamic_cast<CCLabelBMFont*>(hayftTTL);

    if (ttl) {
        // Create a fade-out action
        auto fadeOut = CCFadeOut::create(1.0f);

        // Create a callback to change the text after fading out
        auto changeText = CCCallFuncN::create(this, callfuncN_selector(HAYFT_Popup::changeText));

        // Create a fade-in action
        auto fadeIn = CCFadeIn::create(1.0f);

        // Create a sequence of fade out, change text, and fade in
        auto sequence = CCSequence::create(fadeOut, changeText, fadeIn, nullptr);

        // Run the sequence action on the title
        ttl->runAction(sequence);
    }
}

void HAYFT_Popup::changeText(CCNode* sender) {
    auto ttl = dynamic_cast<CCLabelBMFont*>(sender);
    if (ttl) {
        ttl->setString("God's words for you");
    }
}

void HAYFT_Popup::displayMessage(const std::string& message) {
    auto alert = FLAlertLayer::create(
        nullptr, 
        "Message", 
        message.c_str(), 
        "OK", 
        nullptr
    );
    alert->show();
}
void HAYFT_Popup::displayModuleInfo(const std::string& message) {
    auto alert = FLAlertLayer::create(
        nullptr, 
        "Module Info", 
        message.c_str(), 
        "OK", 
        nullptr
    );
    alert->show();
}



void HAYFT_Popup::onhayftPopupInfoBtn(CCObject* sender) {
    displayModuleInfo("This module is designed to help you express your feelings and emotions through <cr>God's words</c>. Feel free to choose how you feel today and receive a verse that will help you through the day.");
}

void HAYFT_Popup::onHappyBtn(CCObject* sender) {

    auto hayftButtonsMenu = this->getChildByID("cmod-hayft-buttons-menu");
    // Create fade out action
    auto fadeOut = CCFadeOut::create(1.0f); // 2 seconds to fade out

    // Create a sequence of fade out and fade in
    auto sequence = CCSequence::create(fadeOut, nullptr);

    // Run the sequence action on the sprite
    disableHayftButtonsMenu(this);
    hayftButtonsMenu->runAction(sequence);
    updateUIWithTween(this);
}

void HAYFT_Popup::onCalmBtn(CCObject* sender) {
    displayMessage("Peace I leave with you; my peace I give you. - John 14:27");
}

void HAYFT_Popup::onNervousBtn(CCObject* sender) {
    displayMessage("Cast all your anxiety on him because he cares for you. - 1 Peter 5:7");
}

void HAYFT_Popup::onAngryBtn(CCObject* sender) {
    displayMessage("In your anger do not sin: Do not let the sun go down while you are still angry. - Ephesians 4:26");
}

void HAYFT_Popup::onGuiltyBtn(CCObject* sender) {
    displayMessage("If we confess our sins, he is faithful and just and will forgive us our sins. - 1 John 1:9");
}

void HAYFT_Popup::onSadBtn(CCObject* sender) {
    displayMessage("The Lord is close to the brokenhearted and saves those who are crushed in spirit. - Psalm 34:18");
}

void HAYFT_Popup::onBlessedBtn(CCObject* sender) {
    displayMessage("The Lord bless you and keep you; the Lord make his face shine on you. - Numbers 6:24-25");
}

void HAYFT_Popup::onFaithfulBtn(CCObject* sender) {
    displayMessage("Let us hold unswervingly to the hope we profess, for he who promised is faithful. - Hebrews 10:23");
}

void HAYFT_Popup::onFearfulBtn(CCObject* sender) {
    displayMessage("For God has not given us a spirit of fear, but of power and of love and of a sound mind. - 2 Timothy 1:7");
}

void HAYFT_Popup::onThankfulBtn(CCObject* sender) {
    displayMessage("Give thanks to the Lord, for he is good; his love endures forever. - Psalm 107:1");
}

void HAYFT_Popup::onExcitedBtn(CCObject* sender) {
    displayMessage("This is the day that the Lord has made; let us rejoice and be glad in it. - Psalm 118:24");
}

void HAYFT_Popup::onWeakBtn(CCObject* sender) {
    displayMessage("My grace is sufficient for you, for my power is made perfect in weakness. - 2 Corinthians 12:9");
}

