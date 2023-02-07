#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorCollisionBase.h"
#include "CameraStackBehaviorCollisionSweep.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorCollisionSweep : public UCameraStackBehaviorCollisionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckForEyeOverlap;
    
    UCameraStackBehaviorCollisionSweep();
};

