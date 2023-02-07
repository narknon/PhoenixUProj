#pragma once
#include "CoreMinimal.h"
#include "ConsoleVariableStringValue.generated.h"

USTRUCT(BlueprintType)
struct FConsoleVariableStringValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString String;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValid;
    
    CONSOLEMACROS_API FConsoleVariableStringValue();
};

