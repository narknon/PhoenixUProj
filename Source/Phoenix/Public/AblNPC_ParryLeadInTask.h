#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblNPC_ParryLeadInTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNPC_ParryLeadInTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideDBParryLeadIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParryLeadIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CustomProjectileSpeed;
    
public:
    UAblNPC_ParryLeadInTask();
};

