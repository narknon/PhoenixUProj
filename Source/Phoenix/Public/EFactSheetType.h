#pragma once
#include "CoreMinimal.h"
#include "EFactSheetType.generated.h"

UENUM(BlueprintType)
enum class EFactSheetType : uint8 {
    Person,
    Beast,
    Plant,
    Potion,
};

