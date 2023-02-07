#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConsoleMacroConsoleDelegate.generated.h"

UCLASS(Blueprintable, Transient)
class CONSOLEMACROS_API UConsoleMacroConsoleDelegate : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName CommandKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FString Command;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FString Help;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHasExecuted;
    
    UConsoleMacroConsoleDelegate();
};

