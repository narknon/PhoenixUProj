#pragma once
#include "CoreMinimal.h"
#include "ConsoleVariableFloatValue.generated.h"

USTRUCT(BlueprintType)
struct FConsoleVariableFloatValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Float;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValid;
    
    CONSOLEMACROS_API FConsoleVariableFloatValue();
};

