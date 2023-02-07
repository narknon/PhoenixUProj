#pragma once
#include "CoreMinimal.h"
#include "ENPC_Type.generated.h"

UENUM(BlueprintType)
enum class ENPC_Type : uint8 {
    None,
    Enemy,
    Student,
    Creature,
    ENPC_MAX UMETA(Hidden),
};

