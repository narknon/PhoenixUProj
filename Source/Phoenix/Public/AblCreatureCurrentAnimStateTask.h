#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ECreatureMovementSpeed.h"
#include "ECreatureStance.h"
#include "AblCreatureCurrentAnimStateTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCreatureCurrentAnimStateTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureStance CurrentStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureStance NextStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureMovementSpeed CurrentGait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureMovementSpeed NextGait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInIdleVariation;
    
    UAblCreatureCurrentAnimStateTask();
};

