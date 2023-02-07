#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "FXAutoTriggerScalarConsoleVariable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarConsoleVariable : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConsoleVariable;
    
    UFXAutoTriggerScalarConsoleVariable();
};

