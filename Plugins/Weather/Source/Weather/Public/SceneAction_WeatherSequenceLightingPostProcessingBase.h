#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceLightingBase.h"
#include "SceneAction_WeatherSequenceLightingPostProcessingBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceLightingPostProcessingBase : public USceneAction_WeatherSequenceLightingBase {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostSequenceLifetime;
    
    USceneAction_WeatherSequenceLightingPostProcessingBase();
};

