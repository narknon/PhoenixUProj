#pragma once
#include "CoreMinimal.h"
#include "UserConsoleVariable.h"
#include "UserConsoleVariableInt.generated.h"

USTRUCT(BlueprintType)
struct FUserConsoleVariableInt : public FUserConsoleVariable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultValue;
    
    CONSOLEMACROS_API FUserConsoleVariableInt();
};

