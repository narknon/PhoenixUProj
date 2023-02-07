#pragma once
#include "CoreMinimal.h"
#include "UserConsoleVariable.h"
#include "UserConsoleVariableBool.generated.h"

USTRUCT(BlueprintType)
struct FUserConsoleVariableBool : public FUserConsoleVariable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDefaultValue;
    
    CONSOLEMACROS_API FUserConsoleVariableBool();
};

