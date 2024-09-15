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

using namespace geode::prelude;
using namespace cocos2d;


// specify parameters for the setup function in the Popup<...> template
class HAYFT_Popup : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override {
        auto winSize = CCDirector::sharedDirector()->getWinSize();

/* ---------------------------------- Title --------------------------------- */
        auto title = CCLabelBMFont::create("How are you feeling today?", "bigFont.fnt");
        title->setPosition({290.f, 264.f});
        title->setScale(0.675);
        this->addChild(title);
/* --------------------------- HAYFT Buttons menu --------------------------- */
        auto hayftButtonsMenu = CCMenu::create();
        hayftButtonsMenu->setPosition(winSize / 2);
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
        hayftPopup_InfoButtonSpr->setScale(0.8f);

        auto hayftPopup_InfoButton = CCMenuItemSpriteExtra::create(
            hayftPopup_InfoButtonSpr,
            this,
            menu_selector(HAYFT_Popup::onhayftPopupInfoBtn)
        );
        hayftPopup_InfoButton->setID("info-button");
        hayftPopup_InfoButton->setPosition({-182.f, 86.f});
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
/* ----------------------------------- Sad ---------------------------------- */
        auto blessedBtnSprite = CCSprite::create("blessed-complete.png"_spr);
        blessedBtnSprite->setScale(0.105f);
        auto blessedBtn = CCMenuItemSpriteExtra::create(
            blessedBtnSprite, 
            this, 
            menu_selector(HAYFT_Popup::onBlessedBtn)
            );
        blessedBtn->setID("cmod-blessed-btn");
        blessedBtn->setPosition({20.f, -14.f});
/* ------------------- Add buttons to the hayftButtonsMenu ------------------ */
        hayftButtonsMenu->addChild(hayftPopup_InfoButton);

        hayftButtonsMenu->addChild(happyBtn);
        hayftButtonsMenu->addChild(calmBtn);
        hayftButtonsMenu->addChild(nervousBtn);
        hayftButtonsMenu->addChild(angryBtn);
        hayftButtonsMenu->addChild(guiltyBtn);
        hayftButtonsMenu->addChild(sadBtn);
        hayftButtonsMenu->addChild(blessedBtn);
/* ------------------------------ Popup config ------------------------------ */
        m_closeBtn->setPosition({-182.f, 115.f});
        m_bgSprite->setScale(1.55f);
/* ----------------------- Add children to hayft popup ---------------------- */
        this->addChild(hayftForeground);
/* ---------------------------------- Other --------------------------------- */
        return true;
    }

public:
    static HAYFT_Popup* create(std::string const& text) {
        auto ret = new HAYFT_Popup();
        if (ret->init(240.f, 160.f, text)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
    void onhayftPopupInfoBtn(CCObject* sender)
    {
        FLAlertLayer::create(
            "Info",    // title
            "This module is meant to help you connect with <cr>God's word</c> through how you are feeling. Simply select an emotion based on how you are feeling, and you will get random <cr>Bible verse</c> given as <cr>God's word</c> to you.",
            "OK"
        )->show();
    }

    void onHappyBtn(CCObject* sender)
    {

    }
    void onCalmBtn(CCObject* sender)
    {

    }
    void onNervousBtn(CCObject* sender)
    {

    }
    void onAngryBtn(CCObject* sender)
    {

    }
    void onGuiltyBtn(CCObject* sender)
    {

    }
    void onSadBtn(CCObject* sender)
    {

    }
    void onBlessedBtn(CCObject* sender)
    {

    }
};





class ChristianModLayer : public CCLayer {
public:
    struct Fields {

    };
    bool init() {
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

    void onInfoButton(CCObject* sender)
    {
        std::cout<<"Nice!";
    }


    void onPrayButtonPressed(CCObject* sender)
    {
        std::cout<<"Nice!";
    }

    void onHowAreYouFeelingTodayButton(CCObject* sender) 
    {
        auto HowAreYouFeelingTodayPopup = HAYFT_Popup::create("");
        HowAreYouFeelingTodayPopup->setID("hayft-popup");
        this->addChild(HowAreYouFeelingTodayPopup);
    }

    void onClose(CCObject* sender) {
        CCDirector::sharedDirector()->popScene();
    }


    // Static create function to construct the layer
    static ChristianModLayer* create() {
        auto layer = new ChristianModLayer();
        if (layer && layer->init()) {
            layer->autorelease();
            return layer;
        }
        delete layer;
        return nullptr;
    }
};



// Custom Scene Class
class ChristianModScene : public CCScene {
public:
    bool init() {
        if (!CCScene::init()) return false;

        // Add the custom layer to the scene
        auto layer = ChristianModLayer::create();
        this->addChild(layer);
        layer->setID("cmod-main-layer");


        return true;
    }

    // Static create function to construct the scene
    static ChristianModScene* create() {
        auto scene = new ChristianModScene();
        if (scene && scene->init()) {
            scene->autorelease();
            return scene;
        }
        delete scene;
        return nullptr;
    }
};

// Modify the MenuLayer to add the FLAlertLayer with the Verse of the Day popup
class $modify(CustomMenuLayer, MenuLayer) {
public:
    // Use the Fields struct to add custom fields
    struct Fields {
        FLAlertLayer* VOTD_Popup = nullptr;
    };

    bool init() override {
        if (!MenuLayer::init()) return false;

        // Create the Verse of the Day alert and store the reference in m_fields
        m_fields->VOTD_Popup = FLAlertLayer::create(
            this,  // Set this layer as the delegate to handle button callbacks
            "Verse Of The Day",
            "<cr>John 3:16</c> - For God so loved the world that he gave his one and only Son, "
            "that whoever believes in him shall not perish but have eternal life.",
            "AMEN",
            "PRAY"
        );
        m_fields->VOTD_Popup->m_scene = this;
        m_fields->VOTD_Popup->show();

        return true;
    }

    // Overriding the delegate method that is called when a button is clicked in FLAlertLayer
    void FLAlert_Clicked(FLAlertLayer* alert, bool btn2) override {
        // Check if the clicked alert is the Verse of the Day alert
        if (alert == m_fields->VOTD_Popup) {
            if (btn2) {  // If the "PRAY" button (right button) was clicked
                // Create and push the custom scene onto the stack
                auto scene = ChristianModScene::create();
                CCDirector::sharedDirector()->pushScene(scene);
            }
        } 
        // Handle other alerts (like quit game) as needed (or just do nothing)
        else {
            // Handle the default behavior for other alerts
            MenuLayer::FLAlert_Clicked(alert, btn2);
        }
    }
};




class $modify(CustomCreatorLayer, CreatorLayer)
{
    bool init() override {
        if (!CreatorLayer::init()) return false;
        
        auto BibleIcon = CCSprite::create("BibleIcon.png"_spr);

        auto bottomLeftMenu = this->getChildByID("bottom-left-menu");
        auto spr = CircleButtonSprite::createWithSprite("BibleIcon.png"_spr, 1.0f, CircleBaseColor::Green, CircleBaseSize::Small);

        spr->setScale(1.225);

        auto MainMenuButton = CCMenuItemSpriteExtra::create(
            spr,
            this,
            menu_selector(CustomCreatorLayer::onMainMenuButton_Pressed)
        );

        MainMenuButton->setID("cmod-main-menu-button");

        bottomLeftMenu->addChild(MainMenuButton);

        MainMenuButton->setPosition(22.000, 27.000);


        return true;
    }

    // Button press handler
    void onMainMenuButton_Pressed(CCObject* pSender)
    {
        auto scene = ChristianModScene::create();
        CCDirector::sharedDirector()->pushScene(scene);
    }
};


