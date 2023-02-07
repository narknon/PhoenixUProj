#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblSetAllowRMMomentum.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetAllowRMMomentum : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RemoveRMMomentumAtEndOfTask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AddRMMomentum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RemoveRMMomentum;
    
public:
    UAblSetAllowRMMomentum();
};

