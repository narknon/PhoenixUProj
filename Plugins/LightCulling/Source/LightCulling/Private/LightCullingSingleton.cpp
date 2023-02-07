#include "LightCullingSingleton.h"

class AActor;
class ACharacter;
class ULightComponent;
class ULightCullingSettings;
class ULocalLightComponent;
class UObject;

void ALightCullingSingleton::SetVolumetricScatteringIntensity(ULightComponent* Light, float VolumetricScatteringIntensity) {
}

void ALightCullingSingleton::SetOverrideCharacterLightingFeaturesLerp(UObject* WorldContextObject, UObject* OverrideOwner, float Lerp) {
}

void ALightCullingSingleton::SetMobility(ULightComponent* Light, TEnumAsByte<EComponentMobility::Type> Mobility) {
}

void ALightCullingSingleton::SetMaxDrawDistance(ULightComponent* Light, float MaxDrawDistance) {
}

void ALightCullingSingleton::SetMaxDistanceFadeRange(ULightComponent* Light, float MaxDistanceFadeRange) {
}

void ALightCullingSingleton::SetLightShadowSlopeBias(ULocalLightComponent* Light, float ShadowSlopeBias) {
}

void ALightCullingSingleton::SetLightShadowSharpen(ULocalLightComponent* Light, float ShadowSharpen) {
}

void ALightCullingSingleton::SetLightShadowResolutionScale(ULocalLightComponent* Light, float ShadowResolutionScale) {
}

void ALightCullingSingleton::SetLightShadowBias(ULocalLightComponent* Light, float ShadowBias) {
}

void ALightCullingSingleton::SetContactShadowLength(ULightComponent* Light, float ContactShadowLength) {
}

void ALightCullingSingleton::SetCastVolumetricShadow(ULightComponent* Light, bool bCastVolumetricShadow) {
}

void ALightCullingSingleton::SetCastShadowsThreshold(ULightComponent* Light, EShadowQualityLevels ShadowQualityLevel) {
}

void ALightCullingSingleton::SetCastDynamicShadows(ULightComponent* Light, bool bCastShadows) {
}

void ALightCullingSingleton::PushSettings(UObject* WorldContextObject, ULightCullingSettings* Settings) {
}

void ALightCullingSingleton::PopSettings(UObject* WorldContextObject, ULightCullingSettings* Settings) {
}

void ALightCullingSingleton::OverrideCharacterLightingFeatures(UObject* WorldContextObject, UObject* OverrideOwner, FCharacterLightingFeaturesSettings TargetSettings, float Lerp) {
}

bool ALightCullingSingleton::LightCullingUnmanageLightsMobility(AActor* Actor, bool bRestoreMobility) {
    return false;
}

bool ALightCullingSingleton::LightCullingUnmanageLightMobility(ULocalLightComponent* Light, bool bRestoreMobility) {
    return false;
}

void ALightCullingSingleton::LightCullingRemoveIgnoreCharacter(ACharacter* Character, bool& bRemoved) {
}

bool ALightCullingSingleton::LightCullingManageLightsMobility(AActor* Actor) {
    return false;
}

bool ALightCullingSingleton::LightCullingManageLightMobility(ULocalLightComponent* Light) {
    return false;
}

bool ALightCullingSingleton::LightCullingIsManagingLightMobility(ULocalLightComponent* Light) {
    return false;
}

void ALightCullingSingleton::LightCullingIsIgnoredLight(ULightComponent* Light, bool& bIsIgnoredLight) {
}

void ALightCullingSingleton::LightCullingIsIgnoreCharacter(ACharacter* Character, bool& bIsIgnoredCharacter) {
}

void ALightCullingSingleton::LightCullingIgnoreLights(TArray<ULightComponent*> Lights, bool bIgnoreLight) {
}

void ALightCullingSingleton::LightCullingIgnoreLight(ULightComponent* Light, bool bIgnoreLight) {
}

void ALightCullingSingleton::LightCullingAddIgnoreCharacter(ACharacter* Character, bool& bAdded) {
}

void ALightCullingSingleton::GetLightStatus(ULightComponent* Light, ELightCullingLightStatus& Status) {
}

void ALightCullingSingleton::GetEnabled(UObject* WorldContextObject, bool& Enabled) {
}

void ALightCullingSingleton::GetCurrentSettings(UObject* WorldContextObject, ULightCullingSettings*& Settings) {
}

void ALightCullingSingleton::GetCastShadowsThreshold(ULightComponent* Light, EShadowQualityLevels& ShadowQualityLevel) {
}

void ALightCullingSingleton::GetBaseCharacterLightingFeatures(UObject* WorldContextObject, FCharacterLightingFeaturesSettings& CharacterLightingFeaturesSettings) {
}

void ALightCullingSingleton::Flush(ULightComponent* Light) {
}

void ALightCullingSingleton::DisableStart(UObject* WorldContextObject) {
}

void ALightCullingSingleton::DisableEnd(UObject* WorldContextObject) {
}

void ALightCullingSingleton::ClearOverrideCharacterLightingFeatures(UObject* WorldContextObject, UObject* OverrideOwner) {
}

ALightCullingSingleton::ALightCullingSingleton() {
    this->BaseSettings = NULL;
    this->bExternalConsoleDisable = false;
    this->OverrideSettings = NULL;
    this->bEnabled = true;
    this->MobilityManager = NULL;
    this->bFirstUpdate = true;
}

