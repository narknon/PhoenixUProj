#pragma once
#include "CoreMinimal.h"
#include "CloudDefinitionName.h"
#include "SceneAction_WeatherSequence.h"
#include "SceneAction_WeatherSequenceCloudsLegacy.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceCloudsLegacy : public USceneAction_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCloudDefinitionName Definition;
    
    USceneAction_WeatherSequenceCloudsLegacy();
};

