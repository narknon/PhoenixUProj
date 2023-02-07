#pragma once
#include "CoreMinimal.h"
#include "ENPC_CombatThreatLevel.generated.h"

UENUM(BlueprintType)
enum class ENPC_CombatThreatLevel : uint8 {
    Combat_ThreatLevel_None,
    Combat_ThreatLevel_Low,
    Combat_ThreatLevel_Medium,
    Combat_ThreatLevel_High,
    Combat_ThreatLevel_Extreme,
    Combat_ThreatLevel_Boss,
    Combat_ThreatLevel_Count,
    Combat_ThreatLevel_MAX UMETA(Hidden),
};

