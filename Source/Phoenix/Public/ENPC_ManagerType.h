#pragma once
#include "CoreMinimal.h"
#include "ENPC_ManagerType.generated.h"

UENUM(BlueprintType)
enum class ENPC_ManagerType : uint8 {
    None,
    Enemy,
    Student,
    Companion,
    Sidekick,
    Dead,
    Leader,
    Duel,
    AuthorityFig,
    ENPC_MAX UMETA(Hidden),
};

