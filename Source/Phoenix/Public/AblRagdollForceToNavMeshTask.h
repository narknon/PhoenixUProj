#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblRagdollForceToNavMeshTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblRagdollForceToNavMeshTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Force;
    
    UAblRagdollForceToNavMeshTask();
};

