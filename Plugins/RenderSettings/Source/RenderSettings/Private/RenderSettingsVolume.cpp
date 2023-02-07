#include "RenderSettingsVolume.h"

class URenderSettingsLibrary;

void ARenderSettingsVolume::UpdateEnginePostProcessing() {
}

void ARenderSettingsVolume::UpdateEmissiveAdaptation(const URenderSettingsLibrary* Library) {
}

void ARenderSettingsVolume::UpdateDistanceFog(const URenderSettingsLibrary* Library) {
}

void ARenderSettingsVolume::UpdateCharacterLightRigAdjustments(const URenderSettingsLibrary* Library) {
}

void ARenderSettingsVolume::UpdateAll() {
}

void ARenderSettingsVolume::SetPriority(float NewPriority) {
}

void ARenderSettingsVolume::EditProbes() {
}

void ARenderSettingsVolume::EditGroups() {
}

void ARenderSettingsVolume::EditExposure() {
}

void ARenderSettingsVolume::EditDistanceFog() {
}

void ARenderSettingsVolume::EditColorGrading() {
}

void ARenderSettingsVolume::EditAll() {
}

ARenderSettingsVolume::ARenderSettingsVolume() {
    this->ExposureTweak = 0.00f;
    this->IndoorsOutdoors = ERenderSettingsVolumeIndoorsOutdoorsType::IndoorsAndOutdoors;
    this->IndoorsType = ERenderSettingsIndoorsType::ProbeIndoors;
    this->DayNight = ERenderSettingsVolumeDayNightType::DayAndNight;
    this->Overcast = ERenderSettingsVolumeOvercastType::ClearAndOvercast;
    this->LightingMode = EBlendDomainLightingMode::GameAndProbeCapture;
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bUnbounded = false;
    this->bEnabled = true;
    this->bExposureTweak = false;
    this->bDistanceFog = false;
    this->bCharacterLightRigAdjustments = false;
    this->bEmissiveAdaptation = false;
}

