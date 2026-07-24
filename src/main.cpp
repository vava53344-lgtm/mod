#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/binding/GameManager.hpp>
#include <thread>
#include <chrono>

using namespace geode::prelude;

class $modify(LevelEditorLayer) {
    bool init(GJGameLevel* level, bool p1) {
        if (!LevelEditorLayer::init(level, p1)) return false;

        auto alert = geode::createQuickPopup(
            "Editor Purchase",
            "Buy editor for <cy>10,000,000,000</c> orbs?",
            "Cancel", "OK",
            [](auto, bool btn2) {
                if (!btn2) return;

                auto loading = LoadingLayer::create(true);
                loading->show();

                std::thread([loading]() {
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    Loader::get()->queueInMainThread([loading]() {
                        loading->removeFromParent();
                        geode::createQuickPopup(
                            "Success",
                            "You purchased the editor.\n<cy>Orbs were not deducted</c> - this is a joke.",
                            "OK", nullptr,
                            [](auto, bool) {}
                        )->show();
                    });
                }).detach();
            }
        );
        alert->show();

        return true;
    }
};
