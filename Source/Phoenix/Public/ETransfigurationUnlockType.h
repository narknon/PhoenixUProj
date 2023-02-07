#pragma once
#include "CoreMinimal.h"
#include "ETransfigurationUnlockType.generated.h"

UENUM(BlueprintType)
enum class ETransfigurationUnlockType : uint8 {
    Unknown,
    UnknownCurrentlyUnlocked,
    AlwaysUnlocked,
    Vendor,
    CurriculumReward,
    MissionReward,
    Challenge,
    LootDrop,
    Product,
};

