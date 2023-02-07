#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExpHeightFogParameters.h"
#include "GlobalLightingDirectionalLightState.h"
#include "ProbeLightingParameters.h"
#include "SkyAtmosphereParameters.h"
#include "SkyLightLightingParameters.h"
#include "VolumetricCloudsLightingParameters.h"
#include "VolumetricCloudsPresetParameters.h"
#include "VolumetricCloudsWindParameters.h"
#include "GlobalLightingMaster.generated.h"

class AGlobalLightingMaster;
class UDirectionalLightComponent;
class UExponentialHeightFogComponent;
class UGlobalLightingBlendable;
class UGlobalLightingDefaults;
class UObject;
class UPostProcessComponent;
class USkyAtmosphereComponent;
class USkyLightComponent;
class USkyOnlyComponent;
class UVolumetricCloudsComponent;

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API AGlobalLightingMaster : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightingDefaults* Defaults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGlobalLightingBlendable*> OverrideDefaults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGlobalLightingDirectionalLightState CurrentDirectionalLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGlobalLightingDirectionalLightState CurrentSecondaryDirectionalLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSkyLightLightingParameters CurrentSkyLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereParameters CurrentSkyAtmosphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FExpHeightFogParameters CurrentExpHeightFog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FProbeLightingParameters CurrentProbeLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsLightingParameters CurrentCloudsLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsPresetParameters CurrentCloudsPreset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWindParameters CurrentCloudsWind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkyAtmosphereHeightOffsetMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UseExternalLightingComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ControlLightingComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HideExtraLightingComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ControlFeatures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkyLightZOffsetMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkyLightMoveThresholdMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkyLightUpdateThresholdSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float SkyLightAge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBounded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsMaster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDirectionalLightComponent* DirectionalLightComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDirectionalLightComponent* SecondaryDirectionalLightComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkyLightComponent* SkyLightComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExponentialHeightFogComponent* ExpHeightFogComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkyAtmosphereComponent* SkyAtmosphereComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkyOnlyComponent* SkyAtmosphereSkyOnlyComponent;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UDirectionalLightComponent> CachedDirectionalLight;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UDirectionalLightComponent> CachedSecondaryDirectionalLight;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkyLightComponent> CachedSkyLight;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkyAtmosphereComponent> CachedSkyAtmosphere;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UExponentialHeightFogComponent> CachedExpHeightFog;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UVolumetricCloudsComponent> CachedVolumetricClouds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPostProcessComponent* PostProcessComponent;
    
public:
    AGlobalLightingMaster();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetCinematicDefaults(UObject* WorldContextObject, UGlobalLightingDefaults* CinematicDefaults);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetGlobalLightingMaster(UObject* WorldContextObject, AGlobalLightingMaster*& GlobalLightingMaster);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetCinematicDefaults(UObject* WorldContextObject, UGlobalLightingDefaults*& CinematicDefaults);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ClearCinematicDefaults(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    void CheckWorld();
    
    UFUNCTION(BlueprintCallable)
    void CaptureSkyLight();
    
};

