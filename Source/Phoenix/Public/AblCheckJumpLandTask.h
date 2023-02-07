#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblCheckJumpLandTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCheckJumpLandTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPerformTask;
    
public:
    UAblCheckJumpLandTask();
};

