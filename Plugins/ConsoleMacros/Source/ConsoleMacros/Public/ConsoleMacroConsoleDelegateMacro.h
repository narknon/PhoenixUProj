#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroConsoleDelegate.h"
#include "ConsoleMacroConsoleDelegateMacro.generated.h"

UCLASS(Blueprintable, NonTransient)
class CONSOLEMACROS_API UConsoleMacroConsoleDelegateMacro : public UConsoleMacroConsoleDelegate {
    GENERATED_BODY()
public:
    UConsoleMacroConsoleDelegateMacro();
};

