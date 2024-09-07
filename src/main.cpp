// TO GEODE DEVS CHECKING OUT MY CODE:
// SORRY IT ONLY USES ONE FILE, IM TOO LAZY TO CREATE MORE
// ALSO SORRY FOR THE BAD CODE. IM NEW!

#include <Geode/Geode.hpp>
#include <cocos2d.h>

#include <Geode/Enums.hpp>

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/CreatorLayer.hpp>

#include <Geode/modify/CCLayer.hpp>
#include <Geode/modify/CCScene.hpp>

#include <Geode/binding/FLAlertLayer.hpp>

#include <Geode/ui/BasedButtonSprite.hpp>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>

using namespace geode::prelude;
using namespace cocos2d;


class ChristianModLayer : public CCLayer {
public:
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
/*                                   VOTD_BG                                  */
/* -------------------------------------------------------------------------- */
        auto VOTD_BG = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", { .0f, .0f, 80.0f, 80.0f });
        VOTD_BG->setContentSize({ 153.f, 95.f });
        VOTD_BG->setScaleX(1.375);
        VOTD_BG->setScaleY(2.f);
        VOTD_BG->setAnchorPoint({ .5f, 1.f });
        VOTD_BG->setColor({0, 14, 190});
        VOTD_BG->setPosition({135.f, 240.f});
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
        this->addChild(VOTD_BG, 1);
        this->addChild(VOTD_ttl);

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
        VOTD_BG->setID("cmod-votd-bg");
        VOTD_ttl->setID("cmod-votd-ttl");
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
        std::cout<<"Nice!";
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

// Modify the MenuLayer to add the FLAlertLayer instead of a button
class $modify(CustomMenuLayer, MenuLayer) {
    bool init() override {
        if (!MenuLayer::init()) return false;

        // Create the FLAlertLayer with "AMEN" and "PRAY" options
        auto alert = FLAlertLayer::create(
            this,  // Set this layer as the delegate to handle button callbacks
            "Verse Of The Day",
            "<cr>John 3:16</c> - For God so loved the world that he gave his one and only Son, "
            "that whoever believes in him shall not perish but have eternal life.",
            "AMEN",
            "PRAY"
        );
        alert->m_scene = this;
        alert->show();

        return true;
    }

    // Overriding the delegate method that is called when a button is clicked in FLAlertLayer
    void FLAlert_Clicked(FLAlertLayer* alert, bool btn2) override {
        if (btn2) {  // If the "PRAY" button (right button) was clicked
            // Create and push the custom scene onto the stack
            auto scene = ChristianModScene::create();
            CCDirector::sharedDirector()->pushScene(scene);
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


