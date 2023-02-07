#pragma once
#include "CoreMinimal.h"
#include "ENPCRagdollMode.generated.h"

UENUM(BlueprintType)
enum class ENPCRagdollMode : uint8 {
    NoRagdoll,
    FullRagdoll,
    RecoverFromRagdoll,
    ActiveRagdoll,
};

