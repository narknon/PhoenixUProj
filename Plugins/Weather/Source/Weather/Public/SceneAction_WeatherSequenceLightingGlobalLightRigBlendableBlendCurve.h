#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SceneAction_WeatherSequenceLightingGlobalLightRigBlendable.h"
#include "SceneAction_WeatherSequenceLightingGlobalLightRigBlendableBlendCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceLightingGlobalLightRigBlendableBlendCurve : public USceneAction_WeatherSequenceLightingGlobalLightRigBlendable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStretchToDuration;
    
    USceneAction_WeatherSequenceLightingGlobalLightRigBlendableBlendCurve();
};

