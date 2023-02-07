#include "LumosScalabilitySettingsAsset.h"

class AActor;
class ULightComponent;
class ULumosScalabilitySettingsAsset;
class UPostProcessComponent;

void ULumosScalabilitySettingsAsset::LumosScalabilitySetupPostProcessingComponent(const FLumosScalabilitySettings& ScalabilitySettings, UPostProcessComponent* PostProcessComponent, bool& bEnablePostProcessing, bool bMerge) {
}

void ULumosScalabilitySettingsAsset::LumosScalabilitySetupPostProcessing(const FLumosScalabilitySettings& ScalabilitySettings, FPostProcessSettings& PostProcessSettings, bool& bEnablePostProcessing, bool bMerge) {
}

void ULumosScalabilitySettingsAsset::LumosScalabilitySetupLight(const FLumosScalabilitySettings& ScalabilitySettings, ULightComponent* LumosLight) {
}

void ULumosScalabilitySettingsAsset::LumosScalabilityLightMinDistance(const FLumosScalabilitySettings& ScalabilitySettings, float InLightMinDistance, float& OutLightMinDistance) {
}

void ULumosScalabilitySettingsAsset::LumosScalabilityGetSettings(const ULumosScalabilitySettingsAsset* ScalabilitySettingsAsset, AActor* Caster, bool bIsPlayer, FLumosScalabilitySettings& ScalabilitySettings, bool& bFound) {
}

void ULumosScalabilitySettingsAsset::GetLumosScalabilityChangedMessage(FName& HermesMessage) {
}

void ULumosScalabilitySettingsAsset::Get(AActor* Caster, bool bIsPlayer, FLumosScalabilitySettings& ScalabilitySettings) const {
}

ULumosScalabilitySettingsAsset::ULumosScalabilitySettingsAsset() {
}

