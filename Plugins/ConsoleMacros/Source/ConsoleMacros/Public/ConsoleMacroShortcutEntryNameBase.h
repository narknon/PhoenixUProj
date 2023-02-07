#pragma once
#include "CoreMinimal.h"
#include "EConsoleMacroCommandScope.h"
#include "ConsoleMacroShortcutEntryNameBase.generated.h"

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleMacroShortcutEntryNameBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Command;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RestoreValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName AutoRestoreValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EConsoleMacroCommandScope Scope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bNoQuery: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAutoRestoreValue: 1;
    
    FConsoleMacroShortcutEntryNameBase();
};

