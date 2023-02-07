#pragma once
#include "CoreMinimal.h"
#include "ConsoleVariableBoolValue.generated.h"

USTRUCT(BlueprintType)
struct FConsoleVariableBoolValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValid;
    
    CONSOLEMACROS_API FConsoleVariableBoolValue();
};

