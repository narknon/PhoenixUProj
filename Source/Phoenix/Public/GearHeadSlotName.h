#pragma once
#include "CoreMinimal.h"
#include "GearName.h"
#include "GearHeadSlotName.generated.h"

USTRUCT(BlueprintType)
struct FGearHeadSlotName : public FGearName {
    GENERATED_BODY()
public:
    PHOENIX_API FGearHeadSlotName();
};

