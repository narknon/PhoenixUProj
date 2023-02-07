#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblNPC_ParryExternalLeadInTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNPC_ParryExternalLeadInTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalLeadInTime;
    
public:
    UAblNPC_ParryExternalLeadInTask();
};

