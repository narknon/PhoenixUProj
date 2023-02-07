#pragma once
#include "CoreMinimal.h"
#include "EDaysOfTheWeekBitmask.generated.h"

UENUM(BlueprintType)
enum class EDaysOfTheWeekBitmask : uint8 {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
    EveryDay,
};

