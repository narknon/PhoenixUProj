#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "QueueReactionParams.h"
#include "Templates/SubclassOf.h"
#include "AblNpcStartReactionTask.generated.h"

class UAblReactionAbility;
class UAblTaskCondition;

UCLASS(Blueprintable, EditInlineNew)
class UAblNpcStartReactionTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblReactionAbility> ReactionAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskCondition*> TaskConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartReactionOnlyOnce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustPassAllConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCurrentReactionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQueueReactionParams ReactionParams;
    
public:
    UAblNpcStartReactionTask();
};

