#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "Templates/SubclassOf.h"
#include "AblAddPassiveReactionTask.generated.h"

class UAblReactionAbility;
class UAblTaskCondition;

UCLASS(Blueprintable, EditInlineNew)
class UAblAddPassiveReactionTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblReactionAbility> PassiveReactionAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskCondition*> TaskConditions;
    
public:
    UAblAddPassiveReactionTask();
};

