#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConsoleMacroEntry.h"
#include "ConsoleMacroGroupEntry.h"
#include "ConsoleMacroShortcutEntryNameRequired.h"
#include "ConsoleMacrosPluginDefinitions.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=ProjectConsoleMacros)
class CONSOLEMACROS_API UConsoleMacrosPluginDefinitions : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroGroupEntry> Groups;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroShortcutEntryNameRequired> Commands;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroEntry> Macros;
    
    UConsoleMacrosPluginDefinitions();
};

