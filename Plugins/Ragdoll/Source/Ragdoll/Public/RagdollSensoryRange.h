#pragma once
#include "CoreMinimal.h"
#include "ERagdollSensoryRangeValueEnum.h"
#include "RagdollSensoryRange.generated.h"

USTRUCT(BlueprintType)
struct RAGDOLL_API FRagdollSensoryRange {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERagdollSensoryRangeValueEnum SensoryValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Max;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IfOutOfRange;
    
    FRagdollSensoryRange();
};

