#pragma once
#include "CoreMinimal.h"
#include "EGenderEnum.generated.h"

UENUM(BlueprintType)
enum class EGenderEnum : uint8 {
    GENDER_MALE,
    GENDER_FEMALE,
    GENDER_UNKNOWN,
    GENDER_MAX UMETA(Hidden),
};

