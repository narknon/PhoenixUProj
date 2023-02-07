#pragma once
#include "CoreMinimal.h"
#include "EDeflectionType.generated.h"

UENUM(BlueprintType)
enum class EDeflectionType : uint8 {
    Deflect_Block,
    Deflect_Back,
    Deflect_Object,
    Deflect_Enemy,
    Deflect_Random,
    Deflect_MAX UMETA(Hidden),
};

