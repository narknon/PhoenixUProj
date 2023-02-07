#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerNameBase.generated.h"

USTRUCT(BlueprintType)
struct FFXAutoTriggerNameBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FXUTIL_API FFXAutoTriggerNameBase();
};

