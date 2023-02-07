#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacrosAutomation.h"
#include "ConsoleMacrosAutomationLevelSelect.h"
#include "ConsoleMacrosAutomationLevel.generated.h"

USTRUCT(BlueprintType)
struct FConsoleMacrosAutomationLevel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConsoleMacrosAutomationLevelSelect Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConsoleMacrosAutomation Automation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlockEveryLevelAutomations;
    
    CONSOLEMACROS_API FConsoleMacrosAutomationLevel();
};

