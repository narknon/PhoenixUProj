#pragma once
#include "CoreMinimal.h"
#include "ConsoleVariableFlexValue.h"
#include "ConsoleVariableLienEntry.generated.h"

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleVariableLienEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConsoleVariableFlexValue Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    FConsoleVariableLienEntry();
};

