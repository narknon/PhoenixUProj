#pragma once
#include "CoreMinimal.h"
#include "ECharacterPieceGenderEnum.generated.h"

UENUM(BlueprintType)
enum class ECharacterPieceGenderEnum : uint8 {
    GENDER_MALE,
    GENDER_FEMALE,
    GENDER_ANY,
    GENDER_MAX UMETA(Hidden),
};

