// TO GEODE DEVS CHECKING OUT MY CODE:
// SORRY IT ONLY USES ONE FILE, IM TOO LAZY TO CREATE MORE
// ALSO SORRY FOR THE BAD CODE. IM NEW!

#include <Geode/Geode.hpp>
#include <cocos2d.h>

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
            ccc4(0, 33, 255, 255), 
            ccc4(0, 128, 255, 255)
        );
/* -------------------------------------------------------------------------- */
/*                                 Layer Title                                */
/* -------------------------------------------------------------------------- */
        auto ttl = CCLabelBMFont::create("ChristianMod", "goldFont.fnt");
        ttl->setPosition(284.500, 302.000);
        ttl->setScale(1.175);
/* -------------------------------------------------------------------------- */
/*                                Close Button                                */
/* -------------------------------------------------------------------------- */
        auto closeButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
            this,
            menu_selector(ChristianModLayer::onClose)
        );
/* -------------------------------------------------------------------------- */
/*                                HAYFT Button                                */
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
/*                         Scale and position buttons                         */
/* -------------------------------------------------------------------------- */
/* ------------------------------- closeButton ------------------------------ */
        closeButton->setPosition({-12.000, 10.000});
/* ----------------------- HowAreYouFeelingTodayButton ---------------------- */


/* -------------------------------------------------------------------------- */
/*                                Define Menus                                */
/* -------------------------------------------------------------------------- */
        auto closeButtonMenu = CCMenu::create(closeButton, nullptr);
        auto HAYFTMenu = CCMenu::create();
/* -------------------------------------------------------------------------- */
/*                          Scale and position menus                          */
/* -------------------------------------------------------------------------- */
/* ----------------------------- closeButtonMenu ---------------------------- */
        closeButtonMenu->setPosition({ 35, winSize.height - 35 });
/* -------------------------------- HAYFTMenu ------------------------------- */
        HAYFTMenu->setPosition(569.0, 258.0);
        HAYFTMenu->setScale(1.100);
/* -------------------------------------------------------------------------- */
/*                            Add children to menus                           */
/* -------------------------------------------------------------------------- */
        HAYFTMenu->addChild(HowAreYouFeelingTodayButton);
/* -------------------------------------------------------------------------- */
/*                            Add children to layer                           */
/* -------------------------------------------------------------------------- */
        this->addChild(gradient);
        this->addChild(ttl);
/* -------------------------------------------------------------------------- */
/*                             Add menus to layer                             */
/* -------------------------------------------------------------------------- */
        this->addChild(HAYFTMenu);
        this->addChild(closeButtonMenu);
/* -------------------------------------------------------------------------- */
/*                                   Set IDs                                  */
/* -------------------------------------------------------------------------- */
        gradient->setID("bg-gradient");
        ttl->setID("title");
        HAYFTMenu->setID("cmod-top-right-side-menu");
        closeButtonMenu->setID("cmod-close-button-menu");
        closeButton->setID("cmod-close-button");



        return true;
    }
    void onHowAreYouFeelingTodayButton(CCObject* sender)
    {
        std::cout<<"Nice!";
    }
    // "X" button callback to pop the current scene and go back to the previous one
    void onClose(CCObject* sender) {
        // Safely pop the current scene, going back to the previous one
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
            "Daily Bible Verse",
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


