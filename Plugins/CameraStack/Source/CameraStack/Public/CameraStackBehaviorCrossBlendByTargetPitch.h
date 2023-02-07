#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "CameraStackBehaviorMultiCrossBlendStandalone.h"
#include "CameraStackBehaviorCrossBlendByTargetPitch.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorCrossBlendByTargetPitch : public UCameraStackBehaviorMultiCrossBlendStandalone {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve TargetPitchToWeightCurve;
    
    UCameraStackBehaviorCrossBlendByTargetPitch();
};

