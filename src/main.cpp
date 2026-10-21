#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/web.hpp>
#include "ListManager.h"
#include <string>

using namespace geode::prelude;

class $modify(MenuLayer) {
	struct Fields {
        EventListener<web::WebTask> m_listener;
	};

	bool init() {
		if (!MenuLayer::init()) return false;

		if (ListManager::firstTimeOpen) {
			return true;
		}

		std::string currentSource = Mod::get()->getSettingValue<std::string>("demon-list-source");

		if (currentSource == "global") {
			ListManager::parseRequestString("");
			ListManager::firstTimeOpen = true;
			ListManager::filterType = -1;
			return true;
		}

		m_fields->m_listener.bind([currentSource] (web::WebTask::Event* e) {
            if (web::WebResponse* res = e->getValue()) {
                auto str = res->string().unwrapOr("Failed.");
				if (res->code() != 200 || str == "Failed." || str == "-1") {
					ListManager::firstTimeOpen = true;
					ListManager::filterType = -2;
					std::string listName = (currentSource == "pointercrate") ? "Pointercrate" : "AREDL";
					std::string errorStr = "\n\n<cr>Could not load data from " + listName + ".</c>\n\n<cb>-Grandpa Demon</c>";
					FLAlertLayer::create("Error", errorStr, "OK")->show();
					return;
				}
				ListManager::parseRequestString(str);
		 		ListManager::firstTimeOpen = true;
		 		ListManager::filterType = -1;
			}
        });

		std::string targetUrl = "https://aredl.net";
		if (currentSource == "pointercrate") {
			targetUrl = "https://pointercrate.com";
		}

		auto req = web::WebRequest();
		m_fields->m_listener.setFilter(req.get(targetUrl));

		return true;
	}
};
