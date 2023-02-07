#include "InstallManager.h"

class UInstallManager;

void UInstallManager::UninstallFeature(EInstallFeatures FeatureId) {
}

bool UInstallManager::IsLanguageInstalledOrInstalling(const FString& Language) {
    return false;
}

bool UInstallManager::IsInstallingAnyPack() {
    return false;
}

bool UInstallManager::IsInstallingAnyLanguagePack() {
    return false;
}

void UInstallManager::InstallFeature(EInstallFeatures FeatureId) {
}

EFeatureInstallState UInstallManager::GetFeatureInstallState(EInstallFeatures FeatureId) {
    return EFeatureInstallState::NotSupported;
}

float UInstallManager::GetFeatureInstallPercentage(EInstallFeatures FeatureId) {
    return 0.0f;
}

EInstallFeatures UInstallManager::GetCurrentlyInstallingFeatureId() {
    return EInstallFeatures::FullGame;
}

UInstallManager* UInstallManager::Get() {
    return NULL;
}

FString UInstallManager::FindAvailableInstalledLanguage() {
    return TEXT("");
}

UInstallManager::UInstallManager() {
}

