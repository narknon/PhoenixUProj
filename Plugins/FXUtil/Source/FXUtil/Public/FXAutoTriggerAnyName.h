#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerNameBase.h"
#include "FXAutoTriggerAnyName.generated.h"

USTRUCT(BlueprintType)
struct FFXAutoTriggerAnyName : public FFXAutoTriggerNameBase {
    GENERATED_BODY()
public:
    FXUTIL_API FFXAutoTriggerAnyName();
};

