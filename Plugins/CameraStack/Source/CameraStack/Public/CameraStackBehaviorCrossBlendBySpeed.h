#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "CameraStackBehaviorMultiCrossBlendStandalone.h"
#include "CameraStackBehaviorCrossBlendBySpeed.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorCrossBlendBySpeed : public UCameraStackBehaviorMultiCrossBlendStandalone {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve SpeedToWeightCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHorizontalSpeed;
    
    UCameraStackBehaviorCrossBlendBySpeed();
};

