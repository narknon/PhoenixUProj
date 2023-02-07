#pragma once
#include "CoreMinimal.h"
#include "GearName.h"
#include "GearHandSlotName.generated.h"

USTRUCT(BlueprintType)
struct FGearHandSlotName : public FGearName {
    GENERATED_BODY()
public:
    PHOENIX_API FGearHandSlotName();
};

