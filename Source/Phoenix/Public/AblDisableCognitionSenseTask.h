#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "Templates/SubclassOf.h"
#include "AblDisableCognitionSenseTask.generated.h"

class UAISense;

UCLASS(Blueprintable, EditInlineNew)
class UAblDisableCognitionSenseTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAISense>> SensesToDisable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForce;
    
public:
    UAblDisableCognitionSenseTask();
};

