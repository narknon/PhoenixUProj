#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroNameBase.h"
#include "ConsoleMacroName.generated.h"

USTRUCT(BlueprintType)
struct FConsoleMacroName : public FConsoleMacroNameBase {
    GENERATED_BODY()
public:
    CONSOLEMACROS_API FConsoleMacroName();
};

