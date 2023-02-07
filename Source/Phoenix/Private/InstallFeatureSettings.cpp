#include "InstallFeatureSettings.h"

UInstallFeatureSettings::UInstallFeatureSettings() {
    this->bSupportsLanguagePacks = true;
    this->bSupportsLanguagePackInstalling = false;
    this->InstallFeatures.AddDefaulted(10);
}

