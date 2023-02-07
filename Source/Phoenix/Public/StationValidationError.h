#pragma once
#include "CoreMinimal.h"
#include "StationValidationError.generated.h"

USTRUCT(BlueprintType)
struct FStationValidationError {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ShortMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LongMessage;
    
    PHOENIX_API FStationValidationError();
};

