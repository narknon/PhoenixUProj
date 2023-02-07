#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeatherLibrary.generated.h"

class UCloudDefinitions;
class UFogDefinitions;
class UGlobalLightingBlendable;
class URenderSettingsCustomBlendDomain;
class UWeatherPreloads;
class UWeatherSequences;
class UWeatherTypesAsset;
class UWindDefinitions;

UCLASS(Blueprintable)
class WEATHER_API UWeatherLibrary : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWeatherSequences* Sequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFogDefinitions* FogDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCloudDefinitions* CloudDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWindDefinitions* WindDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWeatherTypesAsset* WeatherSurfaceTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendable* DefaultOvercastBlendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* ProhibitWeatherBlendDomain;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWeatherPreloads> WeatherPreloadsAsset;
    
    UWeatherLibrary();
};

