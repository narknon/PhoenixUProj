#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveLinearColor.h"
#include "Curves/CurveFloat.h"
#include "EAnimateLightColorIntensityBlend.h"
#include "SceneAction_AnimateLightColorIntensity.h"
#include "SceneAction_AnimateLightColorAndIntensity.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AnimateLightColorAndIntensity : public USceneAction_AnimateLightColorIntensity {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimateLightColorIntensityBlend ColorBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimateLightColorIntensityBlend IntensityBlend;
    
    USceneAction_AnimateLightColorAndIntensity();
};

