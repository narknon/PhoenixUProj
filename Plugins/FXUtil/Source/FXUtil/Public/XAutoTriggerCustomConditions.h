#pragma once
#include "CoreMinimal.h"
#include "XAutoTriggerPerWorldCustomConditions.h"
#include "XAutoTriggerCustomConditions.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct FXUTIL_API FXAutoTriggerCustomConditions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UWorld*, FXAutoTriggerPerWorldCustomConditions> Conditions;
    
    FXAutoTriggerCustomConditions();
};

