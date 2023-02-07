#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SceneAction_WeatherSequence.h"
#include "SceneAction_WeatherSequenceStormCurve.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceStormCurve : public USceneAction_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStretchToDuration;
    
    USceneAction_WeatherSequenceStormCurve();
};

