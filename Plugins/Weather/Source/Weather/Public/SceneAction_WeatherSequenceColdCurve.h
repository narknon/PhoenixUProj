#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SceneAction_WeatherSequenceCold.h"
#include "SceneAction_WeatherSequenceColdCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceColdCurve : public USceneAction_WeatherSequenceCold {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Cold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStretchToDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendDuration;
    
    USceneAction_WeatherSequenceColdCurve();
};

