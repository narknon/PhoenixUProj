#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorAddArmLengthFromTargetSize.generated.h"

class UCameraStackSecondaryTargetGetter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorAddArmLengthFromTargetSize : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackSecondaryTargetGetter* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve ArmLengthOffsetFromTargetSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateArmLength;
    
    UCameraStackBehaviorAddArmLengthFromTargetSize();
};

