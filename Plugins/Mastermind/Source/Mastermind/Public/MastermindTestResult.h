#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MastermindTestResult.generated.h"

USTRUCT(BlueprintType)
struct MASTERMIND_API FMastermindTestResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSuccess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TestName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime Timestamp;
    
    FMastermindTestResult();
};

