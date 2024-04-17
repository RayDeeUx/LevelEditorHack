#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();
		if (!Mod::get()->getSettingValue<bool>("enabled")) { return; }
		auto editBtnSprite = CCSprite::createWithSpriteFrameName("GJ_editBtn_001.png");
		if (!Loader::get()->isModLoaded("tpdea.betterpause-Better")) { editBtnSprite->setScale(.5f); }
		else { editBtnSprite->setScale(.75f); }
		auto editButton = CCMenuItemSpriteExtra::create(
			editBtnSprite,
			this,
			menu_selector(PauseLayer::onEdit)
		);
		editButton->setID("level-edit-button"_spr);
		if (auto betterPause = Loader::get()->getLoadedMod("tpdea.betterpause-Better")) {
			if (!betterPause->getSettingValue<bool>("level-editor-hack") && betterPause->getSettingValue<int64_t>("type-pause") == 1) {
				getChildByIDRecursive("right-button-menu")->addChild(editButton);
			}
		} else {
			getChildByIDRecursive("right-button-menu")->addChild(editButton);
		}
	}
};
