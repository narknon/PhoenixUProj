#pragma once
#include "CoreMinimal.h"
#include "GearName.h"
#include "GearNeckSlotName.generated.h"

USTRUCT(BlueprintType)
struct FGearNeckSlotName : public FGearName {
    GENERATED_BODY()
public:
    PHOENIX_API FGearNeckSlotName();
};

