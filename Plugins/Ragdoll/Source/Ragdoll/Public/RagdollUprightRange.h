#pragma once
#include "CoreMinimal.h"
#include "ERagdollBodyLineUprightEnum.h"
#include "RagdollUprightRange.generated.h"

USTRUCT(BlueprintType)
struct RAGDOLL_API FRagdollUprightRange {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERagdollBodyLineUprightEnum CompareWorldUpTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Max;
    
    FRagdollUprightRange();
};

