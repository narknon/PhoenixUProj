#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerNameBase.h"
#include "FXAutoTriggerGlobalName.generated.h"

USTRUCT(BlueprintType)
struct FFXAutoTriggerGlobalName : public FFXAutoTriggerNameBase {
    GENERATED_BODY()
public:
    FXUTIL_API FFXAutoTriggerGlobalName();
};

