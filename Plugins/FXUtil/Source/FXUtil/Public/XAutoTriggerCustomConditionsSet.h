#pragma once
#include "CoreMinimal.h"
#include "XAutoTriggerCustomConditionsSet.generated.h"

USTRUCT(BlueprintType)
struct FXAutoTriggerCustomConditionsSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Bools;
    
    FXUTIL_API FXAutoTriggerCustomConditionsSet();
};

