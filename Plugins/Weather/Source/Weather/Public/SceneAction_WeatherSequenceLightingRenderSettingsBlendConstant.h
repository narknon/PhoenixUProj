#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceLightingRenderSettings.h"
#include "SceneAction_WeatherSequenceLightingRenderSettingsBlendConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceLightingRenderSettingsBlendConstant : public USceneAction_WeatherSequenceLightingRenderSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    USceneAction_WeatherSequenceLightingRenderSettingsBlendConstant();
};

