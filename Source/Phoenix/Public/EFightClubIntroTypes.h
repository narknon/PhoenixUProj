#pragma once
#include "CoreMinimal.h"
#include "EFightClubIntroTypes.generated.h"

UENUM(BlueprintType)
enum class EFightClubIntroTypes : uint8 {
    FC_InitiateMatch,
    FC_AdeptMatch,
    FC_ChampionsMatch,
    FC_MAX UMETA(Hidden),
};

