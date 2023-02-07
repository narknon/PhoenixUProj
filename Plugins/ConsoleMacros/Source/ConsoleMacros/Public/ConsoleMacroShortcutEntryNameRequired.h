#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroShortcutEntryNameBase.h"
#include "ConsoleMacroShortcutEntryNameRequired.generated.h"

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleMacroShortcutEntryNameRequired : public FConsoleMacroShortcutEntryNameBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FConsoleMacroShortcutEntryNameRequired();
};

