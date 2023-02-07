#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorPitchFromTargetDistance.generated.h"

class UCameraStackSecondaryTargetGetter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorPitchFromTargetDistance : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackSecondaryTargetGetter* SecondaryTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PitchA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PitchB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve HorizontalDistanceInterpWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve VerticalDistanceInterpWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDistanceToTargetBounds;
    
    UCameraStackBehaviorPitchFromTargetDistance();
};

