#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "SceneActionState_WeatherSequenceLightingBase.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceLightingBase : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentTime;
    
    USceneActionState_WeatherSequenceLightingBase();
};

