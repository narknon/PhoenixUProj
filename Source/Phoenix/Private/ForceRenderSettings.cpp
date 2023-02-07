#include "ForceRenderSettings.h"

void AForceRenderSettings::QueryAll() {
}

bool AForceRenderSettings::IsPlayInEditor() {
    return false;
}

bool AForceRenderSettings::IsEditor() {
    return false;
}

void AForceRenderSettings::ApplyNow() {
}

void AForceRenderSettings::Apply(EForceRenderSettingsPhase Phase) {
}

AForceRenderSettings::AForceRenderSettings() {
    this->bDisableAll = false;
}

