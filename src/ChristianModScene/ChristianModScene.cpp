#pragma once

#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <Geode/Geode.hpp>
#include <Geode/loader/Mod.hpp>
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
#include "ChristianModScene.hpp"
#include "../ChristianModLayer/ChristianModLayer.hpp"

using namespace geode::prelude;
using namespace cocos2d;




bool ChristianModScene::init() {
    if (!CCScene::init()) return false;

    // Add the custom layer to the scene
    auto layer = ChristianModLayer::create();
    this->addChild(layer);
    layer->setID("cmod-main-layer");


    return true;
}

// Static create function to construct the scene
ChristianModScene* ChristianModScene::create() {
    auto scene = new ChristianModScene();
    if (scene && scene->init()) {
        scene->autorelease();
        return scene;
    }
    delete scene;
    return nullptr;
}



