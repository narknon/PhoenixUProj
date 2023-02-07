#pragma once
#include "CoreMinimal.h"
#include "TimeDateChangeValue.h"
#include "TimeChangeRequest.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FTimeChangeRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeDateChangeValue Year;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeDateChangeValue Month;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeDateChangeValue Day;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeDateChangeValue Hours;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeDateChangeValue Minutes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeDateChangeValue Seconds;
    
    FTimeChangeRequest();
};

