#pragma once
#include "CoreMinimal.h"
#include "ECreaturePregnancyState.generated.h"

UENUM(BlueprintType)
enum class ECreaturePregnancyState : uint8 {
    NotPregnant,
    Gestation,
    Incubation,
};

