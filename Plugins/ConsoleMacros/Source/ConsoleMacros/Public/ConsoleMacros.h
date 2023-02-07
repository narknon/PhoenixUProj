#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacro.h"
#include "ConsoleMacroGroup.h"
#include "ConsoleMacroShortcut.h"
#include "ConsoleMacros.generated.h"

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleMacros {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FConsoleMacroGroup> Groups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FConsoleMacroShortcut> GeneralCommands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FConsoleMacro> GeneralMacros;
    
    FConsoleMacros();
};

