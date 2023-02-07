#include "PhoenixPreloadSettings.h"

UPhoenixPreloadSettings::UPhoenixPreloadSettings() {
    this->bPreloadAssets = true;
    this->ClassesToPreload.AddDefaulted(36);
    this->bPreloadArchitectAssets = true;
    this->bPreloadCreatureManagerAssets = true;
}

