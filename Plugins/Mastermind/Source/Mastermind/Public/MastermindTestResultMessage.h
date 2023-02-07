#pragma once
#include "CoreMinimal.h"
#include "MastermindMessage.h"
#include "MastermindTestResult.h"
#include "MastermindTestResultMessage.generated.h"

USTRUCT(BlueprintType)
struct MASTERMIND_API FMastermindTestResultMessage : public FMastermindMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMastermindTestResult> TestResults;
    
    FMastermindTestResultMessage();
};

