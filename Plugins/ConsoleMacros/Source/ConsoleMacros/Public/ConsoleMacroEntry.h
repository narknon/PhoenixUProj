#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroAnyName.h"
#include "EConsoleMacroCommandScope.h"
#include "ConsoleMacroEntry.generated.h"

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleMacroEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleMacroAnyName> Commands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EConsoleMacroCommandScope Scope;
    
    FConsoleMacroEntry();
};

