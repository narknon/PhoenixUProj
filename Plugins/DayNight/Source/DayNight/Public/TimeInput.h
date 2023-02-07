#pragma once
#include "CoreMinimal.h"
#include "EHourAmPm.h"
#include "TimeInput.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FTimeInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Hour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Minute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHourAmPm AmPm;
    
    FTimeInput();
};

