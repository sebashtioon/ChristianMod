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


class Utils {
public:
    int getDayOfYear() {
        time_t t = time(0);
        struct tm* now = localtime(&t);
        return now->tm_yday + 1;
    };

    
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

};