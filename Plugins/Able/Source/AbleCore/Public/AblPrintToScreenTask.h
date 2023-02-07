#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblPrintToScreenTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblPrintToScreenTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DebugMessage;
    
public:
    UAblPrintToScreenTask();
};

