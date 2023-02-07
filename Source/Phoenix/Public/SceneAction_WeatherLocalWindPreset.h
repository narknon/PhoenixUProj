#pragma once
#include "CoreMinimal.h"
#include "WindDefinitionName.h"
#include "SceneAction_WeatherLocalWind.h"
#include "SceneAction_WeatherLocalWindPreset.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WeatherLocalWindPreset : public USceneAction_WeatherLocalWind {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindDefinitionName Preset;
    
    USceneAction_WeatherLocalWindPreset();
};

