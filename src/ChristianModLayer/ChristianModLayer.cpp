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
#include "ChristianModLayer.hpp"
#include "../HAYFT_Popup/HAYFT_Popup.hpp"

using namespace geode::prelude;

/* -------------------------------------------------------------------------- */
/*                                  Protected                                 */
/* -------------------------------------------------------------------------- */
bool ChristianModLayer::init() {

    if (!CCLayer::init()) return false;

/* -------------------------------------------------------------------------- */
/*                              Utility Variables                             */
/* -------------------------------------------------------------------------- */
    auto winSize = CCDirector::sharedDirector()->getWinSize();
/* -------------------------------------------------------------------------- */
/*                             Background Gradient                            */
/* -------------------------------------------------------------------------- */
    auto gradient = CCLayerGradient::create(
        ccc4(0, 128, 255, 255),
        ccc4(0, 33, 255, 255)
    );
/* -------------------------------------------------------------------------- */
/*                                 Layer Title                                */
/* -------------------------------------------------------------------------- */
    auto ttl = CCLabelBMFont::create("ChristianMod", "goldFont.fnt");
    ttl->setPosition(284.500, 302.000);
    ttl->setScale(1.175);
/* -------------------------------------------------------------------------- */
/*                               Layer Subtitle                               */
/* -------------------------------------------------------------------------- */
    auto subttl = CCLabelBMFont::create("by sebashtioon", "chatFont.fnt");
    subttl->setPosition(336.5f, 281.f);
    subttl->setScale(0.6f);
/* -------------------------------------------------------------------------- */
/*                                 closeButton                                */
/* -------------------------------------------------------------------------- */
    auto closeButton = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
        this,
        menu_selector(ChristianModLayer::onClose)
    );
    closeButton->setPosition({-12.000, 10.000});
/* -------------------------------------------------------------------------- */
/*                                 InfoButton                                 */
/* -------------------------------------------------------------------------- */
    auto InfoButton = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_infoBtn_001.png"),
        this,
        menu_selector(ChristianModLayer::onInfoButton)
    );
    InfoButton->setPositionY(48.f);
/* -------------------------------------------------------------------------- */
/*                         HowAreYouFeelingTodayButton                        */
/* -------------------------------------------------------------------------- */
    auto HowAreYouFeelingTodaySPR = CircleButtonSprite::createWithSprite(
        "hayft_icon.png"_spr, 
        1.0f, 
        CircleBaseColor::Green, 
        CircleBaseSize::Small
        );
    HowAreYouFeelingTodaySPR->setScale(1.225);
    auto HowAreYouFeelingTodayButton = CCMenuItemSpriteExtra::create(
        HowAreYouFeelingTodaySPR,
        this,
        menu_selector(ChristianModLayer::onHowAreYouFeelingTodayButton)
    );
/* -------------------------------------------------------------------------- */
/*                                 PrayButton                                 */
/* -------------------------------------------------------------------------- */
    auto prayButtonText = CCLabelBMFont::create("PRAY", "bigFont.fnt");
    prayButtonText->setPosition({ 46.f, 18.f });
    prayButtonText->setScale(.725f);
    auto prayButton = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_longBtn01_001.png"),
        this,
        menu_selector(ChristianModLayer::onPrayButtonPressed));
        prayButton->addChild(prayButtonText);
        prayButton->setPosition({-152.0, -131.0});
/* -------------------------------------------------------------------------- */
/*                                  VOTD_ttl                                  */
/* -------------------------------------------------------------------------- */
    auto VOTD_ttl = CCLabelBMFont::create("Verse Of The Day", "bigFont.fnt");
    VOTD_ttl->setPosition({135.f, 253.f});
    VOTD_ttl->setScale({0.625});
/* -------------------------------------------------------------------------- */
/*                                VOTD_TextArea                               */
/* -------------------------------------------------------------------------- */
    auto VOTD_TextArea = MDTextArea::create("<cr>John 3:16</c> - For God so loved the world that he gave his one and only Son, that whoever believes in him shall not perish but have eternal life.", 
    {200.0, 200.0});
    VOTD_TextArea->setPosition({135.f, 145.f});
    VOTD_TextArea->setScale(0.975);
/* -------------------------------------------------------------------------- */
/*                                Define Menus                                */
/* -------------------------------------------------------------------------- */
    auto closeButtonMenu = CCMenu::create(closeButton, nullptr);
    auto topRightMenu = CCMenu::create();
    auto prayButtonMenu = CCMenu::create();
/* -------------------------------------------------------------------------- */
/*                          Scale and position menus                          */
/* -------------------------------------------------------------------------- */
/* ----------------------------- closeButtonMenu ---------------------------- */
    closeButtonMenu->setPosition({ 35, winSize.height - 35 });
/* ------------------------------ topRightMenu ------------------------------ */
    topRightMenu->setPosition(569.0, 258.0);
    topRightMenu->setScale(1.100);
/* -------------------------------------------------------------------------- */
/*                            Add children to menus                           */
/* -------------------------------------------------------------------------- */
    topRightMenu->addChild(HowAreYouFeelingTodayButton);
    topRightMenu->addChild(InfoButton);
    prayButtonMenu->addChild(prayButton);
/* -------------------------------------------------------------------------- */
/*                            Add children to layer                           */
/* -------------------------------------------------------------------------- */
    this->addChild(gradient);
    this->addChild(ttl);
    this->addChild(subttl);
    this->addChild(VOTD_ttl);
    this->addChild(VOTD_TextArea);

/* -------------------------------------------------------------------------- */
/*                             Add menus to layer                             */
/* -------------------------------------------------------------------------- */
    this->addChild(topRightMenu);
    this->addChild(closeButtonMenu);
    this->addChild(prayButtonMenu);
/* -------------------------------------------------------------------------- */
/*                                   Set IDs                                  */
/* -------------------------------------------------------------------------- */
    gradient->setID("cmod-bg-gradient");
    ttl->setID("cmod-title");
    subttl->setID("cmod-sub-title");
    topRightMenu->setID("cmod-top-right-menu");
    closeButtonMenu->setID("cmod-close-button-menu");
    closeButton->setID("cmod-close-button");
    VOTD_ttl->setID("cmod-votd-ttl");
    VOTD_TextArea->setID("cmod-votd-textarea");
    prayButtonMenu->setID("cmod-pray-button-menu");
    prayButton->setID("cmod-pray-button");



    return true;
}


void ChristianModLayer::onKeyBackClicked() {
    CCDirector::sharedDirector()->popScene();
}








/* -------------------------------------------------------------------------- */
/*                                   Public                                   */
/* -------------------------------------------------------------------------- */

void ChristianModLayer::onInfoButton(CCObject* sender)
{
    log::info("Info button pressed");
}


void ChristianModLayer::onPrayButtonPressed(CCObject* sender)
{
    log::info("Pray button pressed");
}

void ChristianModLayer::onHowAreYouFeelingTodayButton(CCObject* sender) 
{
    auto HowAreYouFeelingTodayPopup = HAYFT_Popup::create(std::string(""));
    HowAreYouFeelingTodayPopup->setID("hayft-popup");
    this->addChild(HowAreYouFeelingTodayPopup);
}

void ChristianModLayer::onClose(CCObject* sender) {
    CCDirector::sharedDirector()->popScene();
}


ChristianModLayer* ChristianModLayer::create() { // create da layer
    auto layer = new ChristianModLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    delete layer;
    return nullptr;
}