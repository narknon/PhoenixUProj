#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroConsoleDelegate.h"
#include "ConsoleMacroConsoleDelegateShortcut.generated.h"

UCLASS(Blueprintable, NonTransient)
class CONSOLEMACROS_API UConsoleMacroConsoleDelegateShortcut : public UConsoleMacroConsoleDelegate {
    GENERATED_BODY()
public:
    UConsoleMacroConsoleDelegateShortcut();
};

