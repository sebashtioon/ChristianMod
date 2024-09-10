// ChristianModLayer.cpp
#include "ChristianModLayer.hpp"
#include "HAYFT_Popup.hpp"

bool ChristianModLayer::init() {
    if (!CCLayer::init()) return false;

    // Your initialization code
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    // Create and configure the layer content

    return true;
}

void ChristianModLayer::onInfoButton(CCObject* sender) {
    std::cout << "Info button clicked!";
}

void ChristianModLayer::onPrayButtonPressed(CCObject* sender) {
    std::cout << "Pray button clicked!";
}

void ChristianModLayer::onHowAreYouFeelingTodayButton(CCObject* sender) {
    auto popup = HAYFT_Popup::create("");
    this->addChild(popup);
}

void ChristianModLayer::onClose(CCObject* sender) {
    CCDirector::sharedDirector()->popScene();
}

ChristianModLayer* ChristianModLayer::create() {
    auto layer = new ChristianModLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    delete layer;
    return nullptr;
}
