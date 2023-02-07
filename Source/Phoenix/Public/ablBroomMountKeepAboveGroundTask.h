#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablBroomMountKeepAboveGroundTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablBroomMountKeepAboveGroundTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinHeightAboveGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDeltaV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VelocityEaseSpeed;
    
    UablBroomMountKeepAboveGroundTask();
};

