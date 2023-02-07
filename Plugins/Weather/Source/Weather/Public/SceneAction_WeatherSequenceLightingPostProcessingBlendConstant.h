#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceLightingPostProcessing.h"
#include "SceneAction_WeatherSequenceLightingPostProcessingBlendConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceLightingPostProcessingBlendConstant : public USceneAction_WeatherSequenceLightingPostProcessing {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    USceneAction_WeatherSequenceLightingPostProcessingBlendConstant();
};

