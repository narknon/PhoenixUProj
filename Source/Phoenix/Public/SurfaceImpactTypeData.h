#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EImpactTypes.h"
#include "ImpactEffectData.h"
#include "SurfaceImpactTypeData.generated.h"

class UWeatherRemapBase;

UCLASS(Blueprintable)
class USurfaceImpactTypeData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherRemapBase*> WeatherRemap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EImpactTypes, FImpactEffectData> ImpactTypeMap;
    
    USurfaceImpactTypeData();
};

