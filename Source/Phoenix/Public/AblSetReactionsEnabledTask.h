#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EStandardManagedPriority.h"
#include "AblSetReactionsEnabledTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetReactionsEnabledTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReactionsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStandardManagedPriority Priority;
    
public:
    UAblSetReactionsEnabledTask();
};

