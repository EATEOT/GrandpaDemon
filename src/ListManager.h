#ifndef LISTMANAGER_H
#define LISTMANAGER_H
#include <Geode/Geode.hpp>
#include <vector>
#include <string>
#include <sstream>

using namespace geode::prelude;

class ListManager {
    public:
        inline static std::vector<int> demonIDList;
        inline static bool firstTimeOpen;
        inline static int filterType;
        inline static bool isSupremeSearching;

        inline static void parseRequestString(std::string str) {
            std::string currentSource = Mod::get()->getSettingValue<std::string>("demon-list-source");
            demonIDList.clear();

            if (currentSource == "global") {
                std::vector<int> globalDefaults = {99034107, 79455799, 84391349, 90154881, 61406830};
                for (int id : globalDefaults) {
                    demonIDList.push_back(id);
                }
                return;
            }

            std::string key = (currentSource == "pointercrate") ? "\"id\"" : "_id";
            size_t isFound = str.find(key);

            while (isFound != std::string::npos) {
                str = str.substr(isFound + (currentSource == "pointercrate" ? 4 : 5));
                size_t findBracket = str.find("}");
                size_t findComma = str.find(",");
                size_t endPos = (findBracket < findComma) ? findBracket : findComma;

                try {
                    int id = std::stoi(str.substr(0, endPos));
                    demonIDList.push_back(id);
                } catch (...) {}

                isFound = str.find(key);
            }
        }

        inline static int getPositionOfID(int id) {
            for (unsigned int i = 0; i < demonIDList.size(); i++) {
                if (demonIDList.at(i) == id) return i;
            }
            return -1;
        }

        inline static CCSprite* getSpriteFromPosition(int pos, bool hasText) {
            if (demonIDList.empty()) return CCSprite::createWithSpriteFrameName("GrD_demon0.png"_spr);
            
            if (pos <= 499 && pos > 249) {
                return CCSprite::createWithSpriteFrameName(hasText ? "GrD_demon0_text.png"_spr : "GrD_demon0.png"_spr);
            }
            if (pos <= 249 && pos > 149) {
                return CCSprite::createWithSpriteFrameName(hasText ? "GrD_demon1_text.png"_spr : "GrD_demon1.png"_spr);
            }
            if (pos <= 149 && pos > 74) {
                return CCSprite::createWithSpriteFrameName(hasText ? "GrD_demon2_text.png"_spr : "GrD_demon2.png"_spr);
            }
            if (pos <= 74 && pos > 24) {
                return CCScribe::createWithSpriteFrameName(hasText ? "GrD_demon3_text.png"_spr : "GrD_demon3.png"_spr);
            }
            if (pos <= 24 && pos > 0) {
                return CCSprite::createWithSpriteFrameName(hasText ? "GrD_demon4_text.png"_spr : "GrD_demon4.png"_spr);
            }
            if (pos == 0) {
                if (Mod::get()->getSettingValue<bool>("grandpa-demon-disable")) {
                    return CCSprite::createWithSpriteFrameName(hasText ? "GrD_demon4_text.png"_spr : "GrD_demon4.png"_spr);
                } else {
                    return CCSprite::createWithSpriteFrameName(hasText ? "GrD_demon5_text.png"_spr : "GrD_demon5.png"_spr);
                }
            }
            return CCSprite::createWithSpriteFrameName(hasText ? "GrD_demon0_text.png"_spr : "GrD_demon0.png"_spr);
        }

        inline static GJSearchObject* getSearchObject(int upper, int lower) {
            std::stringstream download;
            bool first = true;
            
            if (demonIDList.empty()) {
                return GJSearchObject::create(SearchType::Type19, "79455799");
            }

            if (upper >= (int)demonIDList.size()) upper = (int)demonIDList.size() - 1;
            if (lower >= (int)demonIDList.size()) lower = 0;

            if (!(upper == 0 && lower == 0)) {
                for (int i = upper; i > lower; i--) {
                    if (i >= (int)demonIDList.size() || i < 0) continue;
                    if (!first) download << ",";
                    download << std::to_string(ListManager::demonIDList.at(i));
                    first = false;
                }
            } else {
                download << std::to_string(ListManager::demonIDList.at(0));
            }
            
            download << "&gameVersion=22";
            return GJSearchObject::create(SearchType::Type19, download.str());
        }   
};

#endif
