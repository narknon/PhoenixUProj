#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroShortcutEntryNameBase.h"
#include "ConsoleMacroShortcutEntry.generated.h"

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleMacroShortcutEntry : public FConsoleMacroShortcutEntryNameBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseName;
    
    FConsoleMacroShortcutEntry();
};

