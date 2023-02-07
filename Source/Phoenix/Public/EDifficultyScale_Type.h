#pragma once
#include "CoreMinimal.h"
#include "EDifficultyScale_Type.generated.h"

UENUM(BlueprintType)
enum class EDifficultyScale_Type : uint8 {
    None,
    TicketCooldownAdjustment,
    DamageAdjustment,
    HealthAdjustment,
    ParryDodgeAdjustment,
    PerfectParryAdjustment,
    ProtegoDeflectCount,
    ProtegoDecayRate,
    ProtegoDamageAdjustment,
    ProtegoCooldownTime,
    EDifficultyScale_MAX UMETA(Hidden),
};

