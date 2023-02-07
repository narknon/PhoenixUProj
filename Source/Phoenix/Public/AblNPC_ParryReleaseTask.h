#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EEnemy_ParryType.h"
#include "AblNPC_ParryReleaseTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNPC_ParryReleaseTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideDBParryToRelease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParryToRelease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTriggerFiredEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryType FiredEventType;
    
public:
    UAblNPC_ParryReleaseTask();
};

