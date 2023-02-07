#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EEnemy_AbilityEvent.h"
#include "ablAnimEventTask.generated.h"

class UAblTaskCondition;

UCLASS(Blueprintable, EditInlineNew)
class UablAnimEventTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AbilityEvent Event;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AbilityEvent EndEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinIntervalSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskCondition*> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustPassAllConditions;
    
public:
    UablAnimEventTask();
};

