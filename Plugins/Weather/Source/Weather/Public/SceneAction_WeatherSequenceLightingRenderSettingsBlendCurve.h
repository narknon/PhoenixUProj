#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SceneAction_WeatherSequenceLightingRenderSettings.h"
#include "SceneAction_WeatherSequenceLightingRenderSettingsBlendCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceLightingRenderSettingsBlendCurve : public USceneAction_WeatherSequenceLightingRenderSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStretchToDuration;
    
    USceneAction_WeatherSequenceLightingRenderSettingsBlendCurve();
};

