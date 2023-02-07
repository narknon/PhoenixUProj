#pragma once
#include "CoreMinimal.h"
#include "MastermindMessage.h"
#include "MastermindProgressUpdate.generated.h"

USTRUCT(BlueprintType)
struct MASTERMIND_API FMastermindProgressUpdate : public FMastermindMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Message;
    
    FMastermindProgressUpdate();
};

