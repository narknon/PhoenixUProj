#pragma once
#include "CoreMinimal.h"
#include "ConsoleMacroLevelName.generated.h"

USTRUCT(BlueprintType)
struct FConsoleMacroLevelName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    CONSOLEMACROS_API FConsoleMacroLevelName();
};

