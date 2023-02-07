#pragma once
#include "CoreMinimal.h"
#include "GearName.h"
#include "GearOutfitSlotName.generated.h"

USTRUCT(BlueprintType)
struct FGearOutfitSlotName : public FGearName {
    GENERATED_BODY()
public:
    PHOENIX_API FGearOutfitSlotName();
};

