#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorFocusDistanceToTarget.h"
#include "CameraStackBehaviorFocusDistanceToSecondaryTarget.generated.h"

class UCameraStackSecondaryTargetGetter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorFocusDistanceToSecondaryTarget : public UCameraStackBehaviorFocusDistanceToTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackSecondaryTargetGetter* SecondaryTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetToPrimaryTargetIfTargetIsInvalid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepLastFocusDistance;
    
    UCameraStackBehaviorFocusDistanceToSecondaryTarget();
};

