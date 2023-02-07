#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceWind.h"
#include "WindDefinitionName.h"
#include "SceneAction_WeatherSequenceWindLegacy.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceWindLegacy : public USceneAction_WeatherSequenceWind {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindDefinitionName Definition;
    
    USceneAction_WeatherSequenceWindLegacy();
};

