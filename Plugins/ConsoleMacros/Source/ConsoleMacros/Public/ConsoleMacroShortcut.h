#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroCommandBase.h"
#include "ConsoleMacroShortcut.generated.h"

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleMacroShortcut : public FConsoleMacroCommandBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BaseName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Command;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RestoreValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bNoQuery: 1;
    
    FConsoleMacroShortcut();
};

