#pragma once
#include "CoreMinimal.h"
#include "ConsoleVariableIntegerValue.generated.h"

USTRUCT(BlueprintType)
struct FConsoleVariableIntegerValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Integer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValid;
    
    CONSOLEMACROS_API FConsoleVariableIntegerValue();
};

