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
#include "./ChristianModLayer/ChristianModLayer.hpp"
#include "./HAYFT_Popup/HAYFT_Popup.hpp"

using namespace geode::prelude;
using namespace cocos2d;



$execute {
    log::info("Successfully loaded ChristianMod");
}