#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveLinearColor.h"
#include "SceneAction_WeatherSequenceEnvGlobalColor.h"
#include "SceneAction_WeatherSequenceEnvGlobalColorCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceEnvGlobalColorCurve : public USceneAction_WeatherSequenceEnvGlobalColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStretchToDuration;
    
    USceneAction_WeatherSequenceEnvGlobalColorCurve();
};

