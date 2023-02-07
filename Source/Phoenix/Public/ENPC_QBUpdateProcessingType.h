#pragma once
#include "CoreMinimal.h"
#include "ENPC_QBUpdateProcessingType.generated.h"

UENUM(BlueprintType)
enum class ENPC_QBUpdateProcessingType : uint8 {
    NPCList,
    QBAttackData,
    Both,
    Custom,
    ENPC_MAX UMETA(Hidden),
};

