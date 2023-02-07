#pragma once
#include "CoreMinimal.h"
#include "EBossStates.generated.h"

UENUM(BlueprintType)
enum class EBossStates : uint8 {
    BS_None,
    BS_Phase1,
    BS_Phase2,
    BS_Phase3,
    BS_Defeated,
    BS_Victory,
    BS_Finished,
    BS_MAX UMETA(Hidden),
};

