#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroShortcutEntry.h"
#include "ConsoleMacroGroupEntry.generated.h"

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleMacroGroupEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroShortcutEntry> Commands;
    
    FConsoleMacroGroupEntry();
};

