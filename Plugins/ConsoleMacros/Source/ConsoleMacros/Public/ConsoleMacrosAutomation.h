#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroAnyNameWithRestore.h"
#include "ConsoleMacrosAutomation.generated.h"

USTRUCT(BlueprintType)
struct FConsoleMacrosAutomation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroAnyNameWithRestore> OnBeginPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroAnyNameWithRestore> OnEndPlay;
    
    CONSOLEMACROS_API FConsoleMacrosAutomation();
};

