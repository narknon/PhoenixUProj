#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRunningFX.h"
#include "FXAutoTriggerRunningFXList.generated.h"

USTRUCT(BlueprintType)
struct FFXAutoTriggerRunningFXList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FFXAutoTriggerRunningFX> FX;
    
    FXUTIL_API FFXAutoTriggerRunningFXList();
};

