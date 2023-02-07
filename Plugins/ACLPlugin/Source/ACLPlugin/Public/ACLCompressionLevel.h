#pragma once
#include "CoreMinimal.h"
#include "ACLCompressionLevel.generated.h"

UENUM(BlueprintType)
enum ACLCompressionLevel {
    ACLCL_Lowest,
    ACLCL_Low,
    ACLCL_Medium,
    ACLCL_High,
    ACLCL_Highest,
    ACLCL_MAX UMETA(Hidden),
};

