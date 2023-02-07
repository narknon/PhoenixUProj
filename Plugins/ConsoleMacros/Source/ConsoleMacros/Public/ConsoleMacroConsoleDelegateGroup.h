#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroConsoleDelegate.h"
#include "ConsoleMacroConsoleDelegateGroup.generated.h"

UCLASS(Blueprintable, NonTransient)
class CONSOLEMACROS_API UConsoleMacroConsoleDelegateGroup : public UConsoleMacroConsoleDelegate {
    GENERATED_BODY()
public:
    UConsoleMacroConsoleDelegateGroup();
};

