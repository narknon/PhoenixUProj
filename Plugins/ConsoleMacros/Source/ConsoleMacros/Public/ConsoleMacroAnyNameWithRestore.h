#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroNameBase.h"
#include "ConsoleMacroAnyNameWithRestore.generated.h"

USTRUCT(BlueprintType)
struct FConsoleMacroAnyNameWithRestore : public FConsoleMacroNameBase {
    GENERATED_BODY()
public:
    CONSOLEMACROS_API FConsoleMacroAnyNameWithRestore();
};

