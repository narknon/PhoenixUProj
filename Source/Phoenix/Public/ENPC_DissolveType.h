#pragma once
#include "CoreMinimal.h"
#include "ENPC_DissolveType.generated.h"

UENUM(BlueprintType)
enum class ENPC_DissolveType : uint8 {
    Dissolve_None,
    Dissolve_Normal,
    Dissovle_HighDamage,
    Dissovle_Impact,
    ENPC_MAX UMETA(Hidden),
};

