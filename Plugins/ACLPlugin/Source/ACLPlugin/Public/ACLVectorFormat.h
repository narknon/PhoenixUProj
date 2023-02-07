#pragma once
#include "CoreMinimal.h"
#include "ACLVectorFormat.generated.h"

UENUM(BlueprintType)
enum ACLVectorFormat {
    ACLVF_Vector3_96,
    ACLVF_Vector3_Variable,
    ACLVF_Vector3_MAX UMETA(Hidden),
};

