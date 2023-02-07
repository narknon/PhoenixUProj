#include "GameLogicRealmSettings.h"

FGameLogicRealmSettings::FGameLogicRealmSettings() {
    this->RealmPrivacy = EGameLogicRealmPrivacy::Public;
    this->bLocked = false;
    this->ElementPanelBitFlags = 0;
    this->ElementPanelMinimized = 0;
}

