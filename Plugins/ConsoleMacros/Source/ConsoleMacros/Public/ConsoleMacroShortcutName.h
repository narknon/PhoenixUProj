#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroNameBase.h"
#include "ConsoleMacroShortcutName.generated.h"

USTRUCT(BlueprintType)
struct FConsoleMacroShortcutName : public FConsoleMacroNameBase {
    GENERATED_BODY()
public:
    CONSOLEMACROS_API FConsoleMacroShortcutName();
};

