#include "ChristianModScene.hpp"

bool ChristianModScene::init() {
    if (!CCScene::init()) return false;

    // Add custom layer to the scene
    auto layer = ChristianModLayer::create();
    this->addChild(layer);

    return true;
}

ChristianModScene* ChristianModScene::create() {
    auto scene = new ChristianModScene();
    if (scene && scene->init()) {
        scene->autorelease();
        return scene;
    }
    delete scene;
    return nullptr;
}
