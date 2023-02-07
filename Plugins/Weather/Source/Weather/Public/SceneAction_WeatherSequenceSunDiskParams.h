#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceSunDisk.h"
#include "SunDiskOverrides.h"
#include "SceneAction_WeatherSequenceSunDiskParams.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceSunDiskParams : public USceneAction_WeatherSequenceSunDisk {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSunDiskOverrides SunDisk;
    
    USceneAction_WeatherSequenceSunDiskParams();
};

