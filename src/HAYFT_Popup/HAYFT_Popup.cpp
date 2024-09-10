#include "HAYFT_Popup.hpp"
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>

bool HAYFT_Popup::setup(std::string const& value) {
    // Setup the popup UI here
    auto winSize = CCDirector::sharedDirector()->getWinSize();

    // Title
    auto title = CCLabelBMFont::create("How are you feeling today?", "bigFont.fnt");
    title->setPosition({290.f, 264.f});
    title->setScale(0.675);
    this->addChild(title);

    // Foreground setup
    auto foreground = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", { .0f, .0f, 80.0f, 80.0f });
    foreground->setContentSize({ 153.f, 95.f });
    foreground->setAnchorPoint({ .5f, 1.f });
    foreground->setColor({ 123, 60, 31 });
    foreground->setScale(2.05f);
    foreground->setPosition({284.5f, 245.f});
    this->addChild(foreground);

    // Buttons (e.g., Info, Happy, Calm)
    auto infoButton = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png"),
        this,
        menu_selector(HAYFT_Popup::onInfoBtn)
    );
    infoButton->setPosition({169.f, 76.f});

    auto menu = CCMenu::create(infoButton, nullptr);
    menu->setPosition(winSize / 2);
    this->addChild(menu);

    // Close button and other setup configurations
    m_closeBtn->setPosition({-182.f, 115.f});
    m_bgSprite->setScale(1.55f);

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

void HAYFT_Popup::onInfoBtn(CCObject* sender) {
    // Info button logic
}

void HAYFT_Popup::onHappyBtn(CCObject* sender) {
    // Happy button logic
}

void HAYFT_Popup::onCalmBtn(CCObject* sender) {
    // Calm button logic
}
