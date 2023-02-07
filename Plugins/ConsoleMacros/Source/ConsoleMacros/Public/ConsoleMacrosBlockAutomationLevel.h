#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacrosAutomationLevelSelect.h"
#include "ConsoleMacrosBlockAutomationLevel.generated.h"

USTRUCT(BlueprintType)
struct FConsoleMacrosBlockAutomationLevel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConsoleMacrosAutomationLevelSelect Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlockPhases;
    
    CONSOLEMACROS_API FConsoleMacrosBlockAutomationLevel();
};

