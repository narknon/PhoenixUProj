#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroCommandBase.generated.h"

class UConsoleMacroConsoleDelegate;

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleMacroCommandBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UConsoleMacroConsoleDelegate* ConsoleDelegate;
    
public:
    FConsoleMacroCommandBase();
};

