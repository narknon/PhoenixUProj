#pragma once
#include "CoreMinimal.h"
#include "ESleeveLengthEnum.generated.h"

UENUM(BlueprintType)
enum class ESleeveLengthEnum : uint8 {
    SLEEVE_LENGTH_NOSLEEVES,
    SLEEVE_LENGTH_SHORT,
    SLEEVE_LENGTH_MEDIUM,
    SLEEVE_LENGTH_LONG,
    SLEEVE_LENGTH_MAX UMETA(Hidden),
};

