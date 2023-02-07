#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceCold.h"
#include "SceneAction_WeatherSequenceColdConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceColdConstant : public USceneAction_WeatherSequenceCold {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Cold;
    
    USceneAction_WeatherSequenceColdConstant();
};

