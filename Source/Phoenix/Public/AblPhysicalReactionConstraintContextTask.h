#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblPhysicalReactionConstraintContextTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblPhysicalReactionConstraintContextTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConstraintContext;
    
    UAblPhysicalReactionConstraintContextTask();
};

