#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESeasonEnum -FallbackName=ESeasonEnum
#include "GlobalLightingBlendableInterface.h"
#include "BlendDomain.h"
#include "ESeasonEnum.h"
#include "EWeatherSurfaceStormType.h"
#include "WeatherActionContext.h"
#include "WeatherDefinitionName.h"
#include "WeatherEnvironmentalGlobalsExtras.h"
#include "WeatherOverrideStack.h"
#include "WeatherOverrideStackEntry.h"
#include "WeatherSequenceOrigin.h"
#include "WindParametersInstant.h"
#include "WorldWeatherDecalTrackers.h"
#include "WeatherMasterComponent.generated.h"

class AActor;
class UGlobalLightingBlendable;
class UGlobalLightingBlendableWeatherClouds;
class UGlobalLightingBlendableWeatherFog;
class ULiveWeatherSequenceInfo;
class UObject;
class USceneComponent;
class UWeatherMasterComponent;
class UWeatherSequencePendingLoad;
class UWeatherStorm;
class UWorldWeatherDecalDefinitions;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WEATHER_API UWeatherMasterComponent : public UActorComponent, public IGlobalLightingBlendableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULiveWeatherSequenceInfo* CurrentWeatherSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeatherActionContext ActionContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeatherEnvironmentalGlobalsExtras EnvironmentalGlobalsExtras;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWeatherStorm* CurrentStorm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDefinitionName DefaultWeather;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeatherSequenceOrigin OverrideWeather;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeatherSequenceOrigin ConsoleWeather;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldWeatherDecalDefinitions* WorldDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWorldWeatherDecalTrackers WorldDecalTrackers;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CloudsBlendablePriority;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain FogBlendDomain;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FogBlendablePriority;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendable* OverrideOvercastBlendable;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain OvercastBlendDomain;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OvercastBlendablePriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisableCloudsBlendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisableFogBlendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisableOvercastBlendable;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeatherOverrideStack WeatherOverrideStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName CurrentLocalSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* FXRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendableWeatherFog* FogBlendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendableWeatherClouds* CloudsBlendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UWeatherSequencePendingLoad*> PendingLoadQueue;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 CurrentPlayingID;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<uint32, UWeatherSequencePendingLoad*> RestoreWeather;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, float> ExtraWeatherSwaps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bWeatherIsRunning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESeasonEnum CurrentSeason;
    
public:
    UWeatherMasterComponent();
    UFUNCTION(BlueprintCallable)
    static void WeatherFXRemoveFromExtraSwaps(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void WeatherFXIsInExtraSwaps(AActor* Actor, bool& bIsInList);
    
    UFUNCTION(BlueprintCallable)
    static void WeatherFXAddToExtraSwaps(AActor* Actor, float OverrideSwapDistanceMeters, bool bAlwaysSwap);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetOverrideWeather(UObject* WorldContextObject, FName NewOverrideWeather, bool bInstantChange);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetDefaultWeather(UObject* WorldContextObject, FName NewDefaultWeather);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PushWeatherOverride(UObject* WorldContextObject, const FWeatherOverrideStackEntry& Entry, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PopWeatherOverride(UObject* WorldContextObject, UObject* Owner);
    
    UFUNCTION(BlueprintCallable)
    void NextSequence();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void IsSnowing(UObject* WorldContextObject, bool& bIsSnowStorm, EWeatherSurfaceStormType& SnowStormType, float& SnowIntensity, float& SnowCoverage, bool bMaskWithIndoors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void IsRaining(UObject* WorldContextObject, bool& bIsRainStorm, EWeatherSurfaceStormType& RainStormType, float& RainIntensity, float& RainCoverage, bool bMaskWithIndoors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetWeatherWind(UObject* WorldContextObject, FWindParametersInstant& WindParameters, bool& bHaveWeather);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetWeatherMaster(UObject* WorldContextObject, UWeatherMasterComponent*& WeatherMaster);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetWeatherFXRoot(UObject* WorldContextObject, USceneComponent*& FXRootComponent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetValidWeatherPresets(UObject* WorldContextObject, TArray<FName>& WeatherPresets);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetOverrideWeather(UObject* WorldContextObject, FName& CurrentOverrideWeather);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetOvercast(UObject* WorldContextObject, float& Overcast);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetDefaultWeather(UObject* WorldContextObject, FName& CurrentDefaultWeather);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetCurrentWeather(UObject* WorldContextObject, FName& TheCurrentWeather);
    
    
    // Fix for true pure virtual functions not being implemented
};

