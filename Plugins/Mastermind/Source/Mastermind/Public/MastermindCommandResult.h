#pragma once
#include "CoreMinimal.h"
#include "ETestSuccess.h"
#include "MastermindMessage.h"
#include "MastermindCommandResult.generated.h"

class UMastermindJsonObject;

USTRUCT(BlueprintType)
struct MASTERMIND_API FMastermindCommandResult : public FMastermindMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSuccess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ErrorMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETestSuccess TestSuccess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMastermindJsonObject* Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> Artifacts;
    
    FMastermindCommandResult();
};

