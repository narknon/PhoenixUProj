#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroCommandBase.h"
#include "ConsoleMacro.generated.h"

USTRUCT(BlueprintType)
struct CONSOLEMACROS_API FConsoleMacro : public FConsoleMacroCommandBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Commands;
    
    FConsoleMacro();
};

