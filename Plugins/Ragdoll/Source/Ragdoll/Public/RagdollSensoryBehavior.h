#pragma once
#include "CoreMinimal.h"
#include "ERagdollSensoryBehaviorEnum.h"
#include "RagdollSensoryBehavior.generated.h"

class URagdollBehavior;

USTRUCT(BlueprintType)
struct RAGDOLL_API FRagdollSensoryBehavior {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERagdollSensoryBehaviorEnum Relativity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollBehavior* Behavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Status;
    
    FRagdollSensoryBehavior();
};

