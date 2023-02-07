#pragma once
#include "CoreMinimal.h"
#include "FogDefinitionName.h"
#include "SceneAction_WeatherSequenceFog.h"
#include "SceneAction_WeatherSequenceFogLegacy.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceFogLegacy : public USceneAction_WeatherSequenceFog {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFogDefinitionName Definition;
    
    USceneAction_WeatherSequenceFogLegacy();
};

