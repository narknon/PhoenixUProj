#pragma once
#include "CoreMinimal.h"
#include "EDateTimeDayOfWeek.generated.h"

UENUM(BlueprintType)
enum class EDateTimeDayOfWeek : uint8 {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
};

