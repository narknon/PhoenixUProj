#pragma once
#include "CoreMinimal.h"
#include "ERagdollSensoryStatusValueEnum.h"
#include "RagdollSensoryStatus.generated.h"

USTRUCT(BlueprintType)
struct RAGDOLL_API FRagdollSensoryStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERagdollSensoryStatusValueEnum SensoryValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Status;
    
    FRagdollSensoryStatus();
};

