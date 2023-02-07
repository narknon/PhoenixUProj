#pragma once
#include "CoreMinimal.h"
#include "GearName.h"
#include "GearFaceSlotName.generated.h"

USTRUCT(BlueprintType)
struct FGearFaceSlotName : public FGearName {
    GENERATED_BODY()
public:
    PHOENIX_API FGearFaceSlotName();
};

