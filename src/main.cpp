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
using namespace cocos2d;



$execute { // Never used this before so it just seemed cool to do this lol
    log::info("Successfully loaded ChristianMod");
}



// Function to load verses from the file
std::vector<std::string> loadVerses(const std::string& filename) {
    std::vector<std::string> verses;
    std::ifstream file(filename);
    if (!file.is_open()) {
        log::error("Error: Could not open file {}", filename);
        return verses;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            verses.push_back(line);
        }
    }
    file.close();
    return verses;
}

// Function to get the current day of the year
int getDayOfYear() {
    time_t now = time(0);
    tm* localtm = localtime(&now);
    return localtm->tm_yday;
}

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

    void disableHayftButtonsMenu(CCNode* node) {
        auto hayftButtonsMenu = node->getChildByID("cmod-hayft-buttons-menu");
        if (hayftButtonsMenu) {
            auto menu = dynamic_cast<CCMenu*>(hayftButtonsMenu);
            if (menu) {
                menu->setEnabled(false);
            }
        }
    }

    void updateUIWithTween(CCNode* node) {
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

    void changeText(CCNode* sender) {
        auto ttl = dynamic_cast<CCLabelBMFont*>(sender);
        if (ttl) {
            ttl->setString("God's words for you");
        }
    }

    void displayMessage(const std::string& message) {
        auto alert = FLAlertLayer::create(
            nullptr, 
            "Message", 
            message.c_str(), 
            "OK", 
            nullptr
        );
        alert->show();
    }
    void displayModuleInfo(const std::string& message) {
        auto alert = FLAlertLayer::create(
            nullptr, 
            "Module Info", 
            message.c_str(), 
            "OK", 
            nullptr
        );
        alert->show();
    }



    void onhayftPopupInfoBtn(CCObject* sender) {
        displayModuleInfo("This module is designed to help you express your feelings and emotions through <cr>God's words</c>. Feel free to choose how you feel today and receive a verse that will help you through the day.");
    }

    void onHappyBtn(CCObject* sender) {

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

    void onCalmBtn(CCObject* sender) {
        displayMessage("Peace I leave with you; my peace I give you. - John 14:27");
    }

    void onNervousBtn(CCObject* sender) {
        displayMessage("Cast all your anxiety on him because he cares for you. - 1 Peter 5:7");
    }

    void onAngryBtn(CCObject* sender) {
        displayMessage("In your anger do not sin: Do not let the sun go down while you are still angry. - Ephesians 4:26");
    }

    void onGuiltyBtn(CCObject* sender) {
        displayMessage("If we confess our sins, he is faithful and just and will forgive us our sins. - 1 John 1:9");
    }

    void onSadBtn(CCObject* sender) {
        displayMessage("The Lord is close to the brokenhearted and saves those who are crushed in spirit. - Psalm 34:18");
    }

    void onBlessedBtn(CCObject* sender) {
        displayMessage("The Lord bless you and keep you; the Lord make his face shine on you. - Numbers 6:24-25");
    }

    void onFaithfulBtn(CCObject* sender) {
        displayMessage("Let us hold unswervingly to the hope we profess, for he who promised is faithful. - Hebrews 10:23");
    }

    void onFearfulBtn(CCObject* sender) {
        displayMessage("For God has not given us a spirit of fear, but of power and of love and of a sound mind. - 2 Timothy 1:7");
    }

    void onThankfulBtn(CCObject* sender) {
        displayMessage("Give thanks to the Lord, for he is good; his love endures forever. - Psalm 107:1");
    }

    void onExcitedBtn(CCObject* sender) {
        displayMessage("This is the day that the Lord has made; let us rejoice and be glad in it. - Psalm 118:24");
    }

    void onWeakBtn(CCObject* sender) {
        displayMessage("My grace is sufficient for you, for my power is made perfect in weakness. - 2 Corinthians 12:9");
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
        log::info("Info button pressed");
    }


    void onPrayButtonPressed(CCObject* sender)
    {
        log::info("Pray button pressed");
    }

    void onHowAreYouFeelingTodayButton(CCObject* sender) 
    {
        auto HowAreYouFeelingTodayPopup = HAYFT_Popup::create(std::string(""));
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


class $modify(CustomMenuLayer, MenuLayer) {
public:
    struct Fields {
        FLAlertLayer* VOTD_Popup = nullptr;
    };

    bool init() override {
        if (!MenuLayer::init()) return false;

        log::info("CustomMenuLayer::init() started");

        // Verify the file path
        std::string filePath = "C:\\Users\\sebas\\GDmodding\\ChristianMod\\resources\\dailybibleversesniv.txt";
        log::info("Verifying file path: {}", filePath);

        if (!std::filesystem::exists(filePath)) {
            log::error("Error: File does not exist at path {}", filePath);
            return false;
        }

        // Load the verses from the file
        auto verses = loadVerses(filePath);

        // Check if the verses vector is empty
        if (verses.empty()) {
            log::error("Error: No verses found in the file.");
            return false;
        }

        // Log the first verse to ensure it's loaded correctly
        log::info("First verse: {}", verses[0]);

        // Initialize VOTD_Popup if it's null




        // TODO: USE createQuickPopup() INSTEAD OF FLAlertLayer::create() TO CREATE THE POPUP



        if (!m_fields->VOTD_Popup) {
            log::info("Initializing VOTD_Popup");
            m_fields->VOTD_Popup = FLAlertLayer::create(
                nullptr, 
                "Verse of the Day", 
                verses[200].c_str(), 
                "AMEN", 
                "PRAY"
            );
            if (m_fields->VOTD_Popup) {
                log::info("VOTD_Popup created successfully");
                m_fields->VOTD_Popup->setID("cmod-votd-popup");
                m_fields->VOTD_Popup->setZOrder(5);
            } else {
                log::error("Failed to create VOTD_Popup");
                return false;
            }
        }

        // Additional logging and null checks
        if (m_fields->VOTD_Popup) {
            log::info("VOTD_Popup is not null, proceeding to add child.");
            this->addChild(m_fields->VOTD_Popup);
            log::info("VOTD_Popup added as child successfully");
        } else {
            log::error("VOTD_Popup is null, cannot add child.");
            return false;
        }

        log::info("CustomMenuLayer::init() completed successfully");
        return true;
    }

    void FLAlert_Clicked(FLAlertLayer* alert, bool btn2) override {
        if (alert->getID() == "cmod-votd-popup") {
            if (btn2) {
                auto scene = ChristianModScene::create();
                CCDirector::sharedDirector()->pushScene(scene);
            }
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


