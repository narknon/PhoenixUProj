#pragma once
#include "CoreMinimal.h"
#include "UserConsoleVariable.h"
#include "UserConsoleVariableFloat.generated.h"

USTRUCT(BlueprintType)
struct FUserConsoleVariableFloat : public FUserConsoleVariable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultValue;
    
    CONSOLEMACROS_API FUserConsoleVariableFloat();
};

