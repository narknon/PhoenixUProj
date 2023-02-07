#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ECollisionResolutionTaskType.h"
#include "AblSetCollisionResolutionTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetCollisionResolutionTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECollisionResolutionTaskType CollisionResolutionType;
    
    UAblSetCollisionResolutionTask();
};

