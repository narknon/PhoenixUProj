#pragma once
#include "CoreMinimal.h"
#include "TimeInput.h"
#include "TimeSourceSlotSetupTime.generated.h"

USTRUCT(BlueprintType)
struct FTimeSourceSlotSetupTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput Time;
    
    DAYNIGHT_API FTimeSourceSlotSetupTime();
};

