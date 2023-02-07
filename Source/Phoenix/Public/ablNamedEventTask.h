#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablNamedEventTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablNamedEventTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Event;
    
public:
    UablNamedEventTask();
};

