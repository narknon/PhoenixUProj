#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WorldWeatherDecalDefinitions.generated.h"

class UWorldWeatherDecal;

UCLASS(Blueprintable)
class WEATHER_API UWorldWeatherDecalDefinitions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWorldWeatherDecal*> Decals;
    
    UWorldWeatherDecalDefinitions();
};

