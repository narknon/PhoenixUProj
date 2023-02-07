#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroLevelName.h"
#include "EConsoleMacrosAutomationLevelType.h"
#include "ConsoleMacrosAutomationLevelSelect.generated.h"

USTRUCT(BlueprintType)
struct FConsoleMacrosAutomationLevelSelect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EConsoleMacrosAutomationLevelType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConsoleMacroLevelName LevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PartialLevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseLevelName;
    
    CONSOLEMACROS_API FConsoleMacrosAutomationLevelSelect();
};

