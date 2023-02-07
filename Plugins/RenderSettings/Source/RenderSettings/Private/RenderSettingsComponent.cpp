#include "RenderSettingsComponent.h"

class URenderSettingsLibrary;

void URenderSettingsComponent::UpdateEnginePostProcessing() {
}

void URenderSettingsComponent::UpdateEmissiveAdaptation(const URenderSettingsLibrary* Library) {
}

void URenderSettingsComponent::UpdateDistanceFog(const URenderSettingsLibrary* Library) {
}

void URenderSettingsComponent::UpdateCharacterLightRigAdjustments(const URenderSettingsLibrary* Library) {
}

void URenderSettingsComponent::UpdateAll() {
}

void URenderSettingsComponent::SetPriority(float NewPriority) {
}

void URenderSettingsComponent::SetPostProcessing(FRenderSettingsPostProcessing NewPostProcessing) {
}

void URenderSettingsComponent::SetExposureTweak(float NewExposureTweak, bool bEnable) {
}

void URenderSettingsComponent::SetEmissiveAdaptation(FRenderSettingsEmissiveAdaptationName NewEmissiveAdaptation, bool bEnable) {
}

void URenderSettingsComponent::SetDistanceFog(FDistanceFogName NewDistanceFog, bool bEnable) {
}

void URenderSettingsComponent::SetCharacterLightRigAdjustments(FCharacterLightRigAdjustmentsName NewCharacterLightRigAdjustments, bool bEnable) {
}

void URenderSettingsComponent::ClearExposureTweak() {
}

void URenderSettingsComponent::ClearEmissiveAdaptation() {
}

void URenderSettingsComponent::ClearDistanceFog() {
}

void URenderSettingsComponent::ClearCharacterLightRigAdjustments() {
}

URenderSettingsComponent::URenderSettingsComponent() {
    this->ExposureTweak = 0.00f;
    this->IndoorsOutdoors = ERenderSettingsVolumeIndoorsOutdoorsType::IndoorsAndOutdoors;
    this->IndoorsType = ERenderSettingsIndoorsType::ProbeIndoors;
    this->DayNight = ERenderSettingsVolumeDayNightType::DayAndNight;
    this->Overcast = ERenderSettingsVolumeOvercastType::ClearAndOvercast;
    this->LightingMode = EBlendDomainLightingMode::GameAndProbeCapture;
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->bUnbounded = false;
    this->bExposureTweak = false;
    this->bDistanceFog = false;
    this->bCharacterLightRigAdjustments = false;
    this->bEmissiveAdaptation = false;
}

