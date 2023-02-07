#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConsoleMacroAnyName.h"
#include "ConsoleMacroEntry.h"
#include "ConsoleMacroGroupEntry.h"
#include "ConsoleMacroShortcutEntryNameRequired.h"
#include "ConsoleMacros.h"
#include "ConsoleMacrosAutomation.h"
#include "ConsoleMacrosAutomationLevel.h"
#include "ConsoleMacrosBlockAutomationLevel.h"
#include "ConsoleMacrosUserDefinitions.generated.h"

UCLASS(Blueprintable, Config=UserConsoleMacros)
class CONSOLEMACROS_API UConsoleMacrosUserDefinitions : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroGroupEntry> Groups;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroShortcutEntryNameRequired> Commands;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroEntry> Macros;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroAnyName> OnGameStartup;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConsoleMacrosAutomation EveryLevelAutomation;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacrosAutomationLevel> PerLevelAutomation;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacrosBlockAutomationLevel> BlockLevelAutomation;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRunOnGameStartup;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRunEveryLevelAutomation;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRunPerLevelAutomation;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlockAllAutomation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FConsoleMacros LiveMacros;
    
    UConsoleMacrosUserDefinitions();
};

