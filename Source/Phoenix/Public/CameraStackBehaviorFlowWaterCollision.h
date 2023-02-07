#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehavior.h"
#include "CameraStackBehaviorFlowWaterCollision.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorFlowWaterCollision : public UCameraStackBehavior {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProbeSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckForWaterVolumeOverlap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMaintainArmOriginFraming;
    
    UCameraStackBehaviorFlowWaterCollision();
};

