#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryRunToType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryRunToType : uint8 {
    LeadInAndRelease,
    ReleaseImmediately,
    EEnemy_MAX UMETA(Hidden),
};

