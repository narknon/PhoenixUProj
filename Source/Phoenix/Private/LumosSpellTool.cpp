#include "LumosSpellTool.h"

class ALumosEmberActor;
class UObject;

void ALumosSpellTool::TurnOffLumos(const UObject* i_caller) {
}

void ALumosSpellTool::StopLumos() {
}

void ALumosSpellTool::SetLumosVolumetricScatteringIntensity(float Intensity) {
}

void ALumosSpellTool::SetLumosLevelSettingsNew(float IntensityFactor, float Radius, float MinDistance) {
}

void ALumosSpellTool::SetLumosLevelSettings(float Intensity, float Radius, float MinDistance) {
}

void ALumosSpellTool::ResetLumosLevelSettings() {
}

void ALumosSpellTool::ObjectNearSound() {
}

bool ALumosSpellTool::IsLumosActive() {
    return false;
}

float ALumosSpellTool::GetLumosVolumetricScatteringIntensity() {
    return 0.0f;
}

float ALumosSpellTool::GetLumosLevelIntensityFactor() {
    return 0.0f;
}

int32 ALumosSpellTool::GetLumosDebug() {
    return 0;
}

ALumosEmberActor* ALumosSpellTool::GetLumosActor() {
    return NULL;
}

void ALumosSpellTool::DeactivateLumos(EStandardManagedPriority Priority, UObject* InInstigator) {
}

void ALumosSpellTool::ActivateLumos(EStandardManagedPriority Priority, UObject* InInstigator) {
}

ALumosSpellTool::ALumosSpellTool() {
    this->LumosActorClass = NULL;
    this->ObjectNearVolume = 100.00f;
    this->ObjectNearTime = 2.00f;
    this->InterpTimeMS = 500;
    this->LumosMotionStartFX = NULL;
    this->LumosMotionStopFX = NULL;
    this->LumosActor = NULL;
    this->LastLumosActor = NULL;
}

