#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroCommandBase.h"
#include "ConsoleMacroShortcut.h"
#include "ConsoleMacroGroup.generated.h"

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleMacroGroup : public FConsoleMacroCommandBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroShortcut> Commands;
    
    FConsoleMacroGroup();
};

