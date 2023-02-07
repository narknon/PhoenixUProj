#pragma once
#include "CoreMinimal.h"
#include "EDateTimeMonth.h"
#include "DateInput.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FDateInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDateTimeMonth Month;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Day;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Year;
    
    FDateInput();
};

