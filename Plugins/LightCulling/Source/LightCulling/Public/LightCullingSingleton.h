#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EShadowQualityLevels -FallbackName=EShadowQualityLevels
#include "CharacterLightingFeatures.h"
#include "CharacterLightingFeaturesSettings.h"
#include "CharacterLightingFeaturesSettingsOverride.h"
#include "ELightCullingLightStatus.h"
#include "LightCulling.h"
#include "LightCullingSingleton.generated.h"

class ACharacter;
class ULightComponent;
class ULightCullingSettings;
class ULightMobilityManager;
class ULocalLightComponent;
class UObject;

UCLASS(Blueprintable, NotPlaceable, Transient)
class LIGHTCULLING_API ALightCullingSingleton : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightCullingSettings* BaseSettings;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> ExternalDisable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bExternalConsoleDisable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCharacterLightingFeaturesSettingsOverride CharacterLightingFeaturesOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULightCullingSettings* OverrideSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLightCulling LightCulling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCharacterLightingFeatures CharacterLightingFeatures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULightMobilityManager* MobilityManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bFirstUpdate;
    
public:
    ALightCullingSingleton(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static void SetVolumetricScatteringIntensity(ULightComponent* Light, float VolumetricScatteringIntensity);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetOverrideCharacterLightingFeaturesLerp(UObject* WorldContextObject, UObject* OverrideOwner, float Lerp);
    
    UFUNCTION(BlueprintCallable)
    static void SetMobility(ULightComponent* Light, TEnumAsByte<EComponentMobility::Type> Mobility);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaxDrawDistance(ULightComponent* Light, float MaxDrawDistance);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaxDistanceFadeRange(ULightComponent* Light, float MaxDistanceFadeRange);
    
    UFUNCTION(BlueprintCallable)
    static void SetLightShadowSlopeBias(ULocalLightComponent* Light, float ShadowSlopeBias);
    
    UFUNCTION(BlueprintCallable)
    static void SetLightShadowSharpen(ULocalLightComponent* Light, float ShadowSharpen);
    
    UFUNCTION(BlueprintCallable)
    static void SetLightShadowResolutionScale(ULocalLightComponent* Light, float ShadowResolutionScale);
    
    UFUNCTION(BlueprintCallable)
    static void SetLightShadowBias(ULocalLightComponent* Light, float ShadowBias);
    
    UFUNCTION(BlueprintCallable)
    static void SetContactShadowLength(ULightComponent* Light, float ContactShadowLength);
    
    UFUNCTION(BlueprintCallable)
    static void SetCastVolumetricShadow(ULightComponent* Light, bool bCastVolumetricShadow);
    
    UFUNCTION(BlueprintCallable)
    static void SetCastShadowsThreshold(ULightComponent* Light, EShadowQualityLevels ShadowQualityLevel);
    
    UFUNCTION(BlueprintCallable)
    static void SetCastDynamicShadows(ULightComponent* Light, bool bCastShadows);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PushSettings(UObject* WorldContextObject, ULightCullingSettings* Settings);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PopSettings(UObject* WorldContextObject, ULightCullingSettings* Settings);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void OverrideCharacterLightingFeatures(UObject* WorldContextObject, UObject* OverrideOwner, FCharacterLightingFeaturesSettings TargetSettings, float Lerp);
    
    UFUNCTION(BlueprintCallable)
    static bool LightCullingUnmanageLightsMobility(AActor* Actor, bool bRestoreMobility);
    
    UFUNCTION(BlueprintCallable)
    static bool LightCullingUnmanageLightMobility(ULocalLightComponent* Light, bool bRestoreMobility);
    
    UFUNCTION(BlueprintCallable)
    static void LightCullingRemoveIgnoreCharacter(ACharacter* Character, bool& bRemoved);
    
    UFUNCTION(BlueprintCallable)
    static bool LightCullingManageLightsMobility(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool LightCullingManageLightMobility(ULocalLightComponent* Light);
    
    UFUNCTION(BlueprintCallable)
    static bool LightCullingIsManagingLightMobility(ULocalLightComponent* Light);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void LightCullingIsIgnoredLight(ULightComponent* Light, bool& bIsIgnoredLight);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void LightCullingIsIgnoreCharacter(ACharacter* Character, bool& bIsIgnoredCharacter);
    
    UFUNCTION(BlueprintCallable)
    static void LightCullingIgnoreLights(TArray<ULightComponent*> Lights, bool bIgnoreLight);
    
    UFUNCTION(BlueprintCallable)
    static void LightCullingIgnoreLight(ULightComponent* Light, bool bIgnoreLight);
    
    UFUNCTION(BlueprintCallable)
    static void LightCullingAddIgnoreCharacter(ACharacter* Character, bool& bAdded);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLightStatus(ULightComponent* Light, ELightCullingLightStatus& Status);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetEnabled(UObject* WorldContextObject, bool& Enabled);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetCurrentSettings(UObject* WorldContextObject, ULightCullingSettings*& Settings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetCastShadowsThreshold(ULightComponent* Light, EShadowQualityLevels& ShadowQualityLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetBaseCharacterLightingFeatures(UObject* WorldContextObject, FCharacterLightingFeaturesSettings& CharacterLightingFeaturesSettings);
    
    UFUNCTION(BlueprintCallable)
    static void Flush(ULightComponent* Light);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DisableStart(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DisableEnd(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ClearOverrideCharacterLightingFeatures(UObject* WorldContextObject, UObject* OverrideOwner);
    
};

