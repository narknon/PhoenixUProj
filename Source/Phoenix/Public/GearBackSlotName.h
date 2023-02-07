#pragma once
#include "CoreMinimal.h"
#include "GearName.h"
#include "GearBackSlotName.generated.h"

USTRUCT(BlueprintType)
struct FGearBackSlotName : public FGearName {
    GENERATED_BODY()
public:
    PHOENIX_API FGearBackSlotName();
};

