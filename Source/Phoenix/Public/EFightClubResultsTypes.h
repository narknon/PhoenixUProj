#pragma once
#include "CoreMinimal.h"
#include "EFightClubResultsTypes.generated.h"

UENUM(BlueprintType)
enum class EFightClubResultsTypes : uint8 {
    FC_Win,
    FC_Lose,
    FC_MAX UMETA(Hidden),
};

