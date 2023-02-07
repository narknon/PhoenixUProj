#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/Scene.h"
#include "EPhoenixScalabilityPlatform.h"
#include "LumosScalabilitySettings.h"
#include "LumosScalabilitySettingsQuality.h"
#include "LumosScalabilitySettingsAsset.generated.h"

class AActor;
class ULightComponent;
class ULumosScalabilityModifyBase;
class ULumosScalabilityOverrideBase;
class ULumosScalabilitySettingsAsset;
class UPostProcessComponent;

UCLASS(Blueprintable)
class ULumosScalabilitySettingsAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLumosScalabilitySettingsQuality PlayerLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLumosScalabilitySettingsQuality NPCLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FLumosScalabilitySettingsQuality> CustomLevels;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPhoenixScalabilityPlatform, FLumosScalabilitySettingsQuality> PerPlatformPlayerLevels;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPhoenixScalabilityPlatform, FLumosScalabilitySettingsQuality> PerPlatformNPCLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULumosScalabilityOverrideBase*> SettingsOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULumosScalabilityModifyBase*> Modifiers;
    
    ULumosScalabilitySettingsAsset();
    UFUNCTION(BlueprintCallable)
    static void LumosScalabilitySetupPostProcessingComponent(const FLumosScalabilitySettings& ScalabilitySettings, UPostProcessComponent* PostProcessComponent, bool& bEnablePostProcessing, bool bMerge);
    
    UFUNCTION(BlueprintCallable)
    static void LumosScalabilitySetupPostProcessing(const FLumosScalabilitySettings& ScalabilitySettings, FPostProcessSettings& PostProcessSettings, bool& bEnablePostProcessing, bool bMerge);
    
    UFUNCTION(BlueprintCallable)
    static void LumosScalabilitySetupLight(const FLumosScalabilitySettings& ScalabilitySettings, ULightComponent* LumosLight);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void LumosScalabilityLightMinDistance(const FLumosScalabilitySettings& ScalabilitySettings, float InLightMinDistance, float& OutLightMinDistance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void LumosScalabilityGetSettings(const ULumosScalabilitySettingsAsset* ScalabilitySettingsAsset, AActor* Caster, bool bIsPlayer, FLumosScalabilitySettings& ScalabilitySettings, bool& bFound);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLumosScalabilityChangedMessage(FName& HermesMessage);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void Get(AActor* Caster, bool bIsPlayer, FLumosScalabilitySettings& ScalabilitySettings) const;
    
};

