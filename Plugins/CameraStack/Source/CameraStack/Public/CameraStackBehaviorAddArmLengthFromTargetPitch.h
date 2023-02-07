#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorAddArmLengthFromTargetPitch.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorAddArmLengthFromTargetPitch : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve PitchToArmLengthOffsetCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpSpeed;
    
    UCameraStackBehaviorAddArmLengthFromTargetPitch();
};

