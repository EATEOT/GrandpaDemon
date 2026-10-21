#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include "ListManager.h"

using namespace geode::prelude;

class $modify(LevelSearchLayer) {
    bool init(int p0) {
        if (!LevelSearchLayer::init(p0)) return false;

        // Фикс логики поиска для новой версии Geode 3.4+
        if (ListManager::isSupremeSearching) {
            ListManager::isSupremeSearching = false;
        }

        return true;
    }
};
