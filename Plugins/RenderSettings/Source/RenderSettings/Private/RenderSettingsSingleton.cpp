#include "RenderSettingsSingleton.h"
#include "PlayerCentricPostProcessingComponent.h"

class UDirectionalLightComponent;
class UObject;

float ARenderSettingsSingleton::RenderSettingsGetOvercast(UObject* WorldContextObject) {
    return 0.0f;
}

float ARenderSettingsSingleton::RenderSettingsGetIndoors(UObject* WorldContextObject, ERenderSettingsIndoorsType IndoorsType) {
    return 0.0f;
}

float ARenderSettingsSingleton::RenderSettingsGetDayNight(UObject* WorldContextObject) {
    return 0.0f;
}

void ARenderSettingsSingleton::PushPlayerViewpointOverride(UObject* WorldContextObject, UObject* ViewpointOverrideOwner, float PostProcessingViewpointOverride, float LerpAlpha) {
}

void ARenderSettingsSingleton::PopPlayerViewpointOverride(UObject* WorldContextObject, UObject* ViewpointOverrideOwner) {
}

void ARenderSettingsSingleton::IsPlayerIndoors(UObject* WorldContextObject, float& Indoors0To1, bool& bIsIndoors) {
}

void ARenderSettingsSingleton::IsCameraIndoors(UObject* WorldContextObject, float& Indoors0To1, bool& bIsIndoors) {
}

void ARenderSettingsSingleton::HasPlayerViewpointOverride(UObject* WorldContextObject, UObject* ViewpointOverrideOwner, bool& bExists) {
}

void ARenderSettingsSingleton::GetViewpointIsInside(UObject* WorldContextObject, float& Indoors, ERenderSettingsIndoorsType IndoorsType) {
}

void ARenderSettingsSingleton::GetViewpointBlendDomain(UObject* WorldContextObject, FBlendDomainState& BlendDomainState) {
}

void ARenderSettingsSingleton::GetPlayerIsInside(UObject* WorldContextObject, float& Indoors, ERenderSettingsIndoorsType IndoorsType) {
}

void ARenderSettingsSingleton::GetPlayerBlendDomain(UObject* WorldContextObject, FBlendDomainState& BlendDomainState) {
}

float ARenderSettingsSingleton::GetOvercast(UObject* WorldContextObject) {
    return 0.0f;
}

float ARenderSettingsSingleton::GetIndoors(UObject* WorldContextObject) {
    return 0.0f;
}

float ARenderSettingsSingleton::GetFilteredIndoors(UObject* WorldContextObject) {
    return 0.0f;
}

float ARenderSettingsSingleton::GetDayNight(UObject* WorldContextObject) {
    return 0.0f;
}

void ARenderSettingsSingleton::GetCameraIsInside(UObject* WorldContextObject, float& Indoors, ERenderSettingsIndoorsType IndoorsType) {
}

void ARenderSettingsSingleton::GetCameraBlendDomain(UObject* WorldContextObject, FBlendDomainState& BlendDomainState) {
}

void ARenderSettingsSingleton::GetBlendDomainValueBool(const FBlendDomainState& BlendDomainState, FName BlendDomain, bool& bValue) {
}

void ARenderSettingsSingleton::GetBlendDomainValue(const FBlendDomainState& BlendDomainState, FName BlendDomain, float& Value) {
}

void ARenderSettingsSingleton::GetBlendDomainIndoors(const FBlendDomainState& BlendDomainState, float& Indoors, ERenderSettingsIndoorsType IndoorsType) {
}

UDirectionalLightComponent* ARenderSettingsSingleton::GetBestDirectionalLight(UObject* WorldContextObject) {
    return NULL;
}

void ARenderSettingsSingleton::CustomBlendDomainSetOverride(UObject* WorldContextObject, FName CustomBlendDomainName, float Value) {
}

void ARenderSettingsSingleton::CustomBlendDomainHasOverride(UObject* WorldContextObject, FName CustomBlendDomainName, bool& bExists) {
}

void ARenderSettingsSingleton::CustomBlendDomainGetOverride(UObject* WorldContextObject, FName CustomBlendDomainName, float& Value, bool& bExists) {
}

void ARenderSettingsSingleton::CustomBlendDomainGetBool(UObject* WorldContextObject, FName CustomBlendDomainName, bool& bValue, bool bDefaultValue) {
}

void ARenderSettingsSingleton::CustomBlendDomainGet(UObject* WorldContextObject, FName CustomBlendDomainName, float& Value, bool& bExists) {
}

void ARenderSettingsSingleton::CustomBlendDomainExists(UObject* WorldContextObject, FName CustomBlendDomainName, bool& bExists) {
}

void ARenderSettingsSingleton::CustomBlendDomainClearOverride(UObject* WorldContextObject, FName CustomBlendDomainName) {
}

float ARenderSettingsSingleton::CurrentPlayerViewpointOverride(UObject* WorldContextObject) {
    return 0.0f;
}

void ARenderSettingsSingleton::ComputeIsInside(UObject* WorldContextObject, FVector Position, float& Indoors, ERenderSettingsIndoorsType IndoorsType, bool bHighQuality) {
}

void ARenderSettingsSingleton::ComputeBlendDomain(UObject* WorldContextObject, FVector Position, FBlendDomainState& BlendDomainState, bool bHighQuality) {
}

ARenderSettingsSingleton::ARenderSettingsSingleton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCreatedInInactiveWorld = false;
    this->PlayerCentricPostProcessing = CreateDefaultSubobject<UPlayerCentricPostProcessingComponent>(TEXT("PlayerCentricPP"));
    this->ViewpointEye0Player1Lerp = 0.00f;
    this->ActiveEditorViewport = -1;
    this->LastCameraCutFrame = 0;
    this->LastExposureRenderCutFrame = 0;
    this->bInExposureRenderingCut = false;
    this->bIsFixedExposure = false;
    this->DebugPostProcessComponent = NULL;
}

