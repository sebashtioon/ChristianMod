#pragma once
#include <Geode/ui/Popup.hpp>

class HAYFT_Popup : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override;

public:
    static HAYFT_Popup* create(std::string const& text);


    void onInfoBtn(CCObject* sender);
    void onHappyBtn(CCObject* sender);
    void onCalmBtn(CCObject* sender);
};
