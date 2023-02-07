#pragma once
#include "CoreMinimal.h"
#include "EGenderPronoun.generated.h"

UENUM(BlueprintType)
enum class EGenderPronoun : uint8 {
    GENDER_WIZARD,
    GENDER_WITCH,
    GENDER_MAX UMETA(Hidden),
};

