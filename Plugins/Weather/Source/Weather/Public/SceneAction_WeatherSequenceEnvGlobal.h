#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequence.h"
#include "SceneAction_WeatherSequenceEnvGlobal.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceEnvGlobal : public USceneAction_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnsetAtEndOfSequence;
    
    USceneAction_WeatherSequenceEnvGlobal();
};

