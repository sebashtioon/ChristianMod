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
#include "HAYFT_Popup.hpp"
#include "ChristianModScene.hpp"

using namespace geode::prelude;
using namespace cocos2d;

// Keep CustomMenuLayer in the main file
class $modify(CustomMenuLayer, MenuLayer) {
public:
    struct Fields {
        FLAlertLayer* VOTD_Popup = nullptr;
    };

    bool init() override {
        if (!MenuLayer::init()) return false;

        m_fields->VOTD_Popup = FLAlertLayer::create(
            this,
            "Verse Of The Day",
            "<cr>John 3:16</c> - For God so loved the world...",
            "AMEN",
            "PRAY"
        );
        m_fields->VOTD_Popup->m_scene = this;
        m_fields->VOTD_Popup->show();

        return true;
    }

    void FLAlert_Clicked(FLAlertLayer* alert, bool btn2) override {
        if (alert == m_fields->VOTD_Popup && btn2) {
            auto scene = ChristianModScene::create();
            CCDirector::sharedDirector()->pushScene(scene);
        } else {
            MenuLayer::FLAlert_Clicked(alert, btn2);
        }
    }
};

// Keep CustomCreatorLayer in the main file
class $modify(CustomCreatorLayer, CreatorLayer) {
    bool init() override {
        if (!CreatorLayer::init()) return false;

        auto BibleIcon = CCSprite::create("BibleIcon.png"_spr);
        auto bottomLeftMenu = this->getChildByID("bottom-left-menu");

        auto MainMenuButton = CCMenuItemSpriteExtra::create(
            BibleIcon,
            this,
            menu_selector(CustomCreatorLayer::onMainMenuButton_Pressed)
        );
        bottomLeftMenu->addChild(MainMenuButton);
        MainMenuButton->setPosition(22.0f, 27.0f);

        return true;
    }

    void onMainMenuButton_Pressed(CCObject* pSender) {
        auto scene = ChristianModScene::create();
        CCDirector::sharedDirector()->pushScene(scene);
    }
};
