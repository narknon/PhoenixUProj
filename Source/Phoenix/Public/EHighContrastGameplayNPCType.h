#pragma once
#include "CoreMinimal.h"
#include "EHighContrastGameplayNPCType.generated.h"

UENUM(BlueprintType)
enum class EHighContrastGameplayNPCType : uint8 {
    Player,
    LeadNPC,
    Companion,
    Friendly,
    Enemy,
};

