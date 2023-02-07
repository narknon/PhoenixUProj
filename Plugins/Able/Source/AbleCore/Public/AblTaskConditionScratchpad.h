#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblTaskConditionScratchpad.generated.h"

UCLASS(Abstract, Blueprintable, Transient)
class ABLECORE_API UAblTaskConditionScratchpad : public UObject {
    GENERATED_BODY()
public:
    UAblTaskConditionScratchpad();
};

