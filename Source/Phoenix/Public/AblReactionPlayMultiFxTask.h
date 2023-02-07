#pragma once
#include "CoreMinimal.h"
#include "AblPlayMultiFxTask.h"
#include "EReactionPlayMultiFxTaskType.h"
#include "AblReactionPlayMultiFxTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblReactionPlayMultiFxTask : public UAblPlayMultiFxTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EReactionPlayMultiFxTaskType ReactionInfoType;
    
    UAblReactionPlayMultiFxTask();
};

