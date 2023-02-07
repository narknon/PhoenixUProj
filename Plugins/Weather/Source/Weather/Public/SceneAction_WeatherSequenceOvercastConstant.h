#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceOvercast.h"
#include "SceneAction_WeatherSequenceOvercastConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceOvercastConstant : public USceneAction_WeatherSequenceOvercast {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Overcast;
    
    USceneAction_WeatherSequenceOvercastConstant();
};

