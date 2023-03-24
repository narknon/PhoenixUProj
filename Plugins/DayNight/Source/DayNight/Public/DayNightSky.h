#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "GlobalLightingBlendableInterface.h"
#include "MilkyWay.h"
#include "MoonDisk.h"
#include "Planet.h"
#include "PlanetParams.h"
#include "StarrySkyCurveParameters.h"
#include "StarrySkyParameters.h"
#include "SunDisk.h"
#include "DayNightSky.generated.h"

class ADayNightSky;
class UDayNightCompass;
class UDayNightMasterComponent;
class UGlobalLightingBlendableDayNightSky;
class UNiagaraStarrySkySwitchableHighlightComponent;
class UNiagaraSystem;
class UObject;
class URenderSettingsBlendDomainAsset;
class USceneComponent;

UCLASS(Blueprintable)
class DAYNIGHT_API ADayNightSky : public AActor, public IGlobalLightingBlendableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDayNightMasterComponent* DayNightMaster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* TrackEyeXYRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendableDayNightSky* GlobalLightingBlendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GlobalLightingBlendablePriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSunDisk SunDisk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMoonDisk MoonDisk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlanetParams Planets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlanet Venus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlanet Mars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlanet Jupiter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlanet Saturn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMilkyWay MilkyWay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> StarFieldSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> HighlightStarFieldSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraStarrySkySwitchableHighlightComponent* StarField;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStarrySkyCurveParameters MoonParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FStarrySkyParameters CurrentMoonParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D HideStarsNormalizedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsBlendDomainAsset* NightSkyVisibilityBlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NightSkyVisibilityBlendDomainThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableSunDisk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseActorZForWorldOrigin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseHideStarsNormalizedTime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDayNightCompass* Compass;
    
public:
    ADayNightSky(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetDayNightSky(UObject* WorldContextObject, ADayNightSky*& DayNightSkyActor);
    
    UFUNCTION(BlueprintCallable)
    void EditLightRig() const;
    
    UFUNCTION(BlueprintCallable)
    void EditBasis() const;
    
    
    // Fix for true pure virtual functions not being implemented
};

