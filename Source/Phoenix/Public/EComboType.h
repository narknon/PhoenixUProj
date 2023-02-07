#pragma once
#include "CoreMinimal.h"
#include "EComboType.generated.h"

UENUM(BlueprintType)
enum class EComboType : uint8 {
    None,
    Hit_Light,
    Hit_Parry,
    Hit_Heavy,
    Hit_Heavy_2_Plus,
    Hit_Depulso_Oppugno,
    Hit_SendTarget,
    Hit_Finisher,
    ProtegoImpact,
};

