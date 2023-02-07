#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroNameBase.h"
#include "ConsoleMacroAnyName.generated.h"

USTRUCT(BlueprintType)
struct FConsoleMacroAnyName : public FConsoleMacroNameBase {
    GENERATED_BODY()
public:
    CONSOLEMACROS_API FConsoleMacroAnyName();
};

