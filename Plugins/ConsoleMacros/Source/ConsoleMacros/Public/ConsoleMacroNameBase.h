#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroNameBase.generated.h"

USTRUCT(BlueprintType)
struct FConsoleMacroNameBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    CONSOLEMACROS_API FConsoleMacroNameBase();
};

