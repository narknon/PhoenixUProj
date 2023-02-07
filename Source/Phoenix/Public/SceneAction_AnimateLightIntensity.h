#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "EAnimateLightColorIntensityBlend.h"
#include "SceneAction_AnimateLightColorIntensity.h"
#include "SceneAction_AnimateLightIntensity.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AnimateLightIntensity : public USceneAction_AnimateLightColorIntensity {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Default;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimateLightColorIntensityBlend Blend;
    
    USceneAction_AnimateLightIntensity();
};

