#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerNameBase.h"
#include "FXAutoTriggerGroupName.generated.h"

USTRUCT(BlueprintType)
struct FFXAutoTriggerGroupName : public FFXAutoTriggerNameBase {
    GENERATED_BODY()
public:
    FXUTIL_API FFXAutoTriggerGroupName();
};

