#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SceneAction_WeatherSequenceLightingPostProcessing.h"
#include "SceneAction_WeatherSequenceLightingPostProcessingBlendCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceLightingPostProcessingBlendCurve : public USceneAction_WeatherSequenceLightingPostProcessing {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStretchToDuration;
    
    USceneAction_WeatherSequenceLightingPostProcessingBlendCurve();
};

