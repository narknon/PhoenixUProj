#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveLinearColor.h"
#include "EAnimateLightColorIntensityBlend.h"
#include "SceneAction_AnimateLightColorIntensity.h"
#include "SceneAction_AnimateLightColor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AnimateLightColor : public USceneAction_AnimateLightColorIntensity {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Default;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimateLightColorIntensityBlend Blend;
    
    USceneAction_AnimateLightColor();
};

