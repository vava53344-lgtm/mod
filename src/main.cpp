#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/binding/GameManager.hpp>
#include <Geode/binding/SimplePlayer.hpp>
#include <thread>
#include <chrono>

using namespace geode::prelude;

class $modify(LevelEditorLayer) {
    bool init(GJGameLevel* level, bool p1) {
        if (!LevelEditorLayer::init(level, p1)) return false;

        // Создаём диалог
        auto alert = geode::createQuickPopup(
            "Покупка редактора",
            "Купить редактор за <cy>10,000,000,000</c> орбов?",
            "Отмена", "Окей",
            [](auto, bool btn2) {
                if (!btn2) return;

                // Показываем загрузку
                auto loading = LoadingLayer::create(true);
                loading->show();

                // Имитация оплаты
                std::thread([loading]() {
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    Loader::get()->queueInMainThread([loading]() {
                        loading->removeFromParent();
                        geode::createQuickPopup(
                            "Успешно!",
                            "Вы оплатили редактор.\n<cy>Орбы не списаны</c> — это шутка! 😄",
                            "Ок", nullptr,
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
