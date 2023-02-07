#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblZeroVelocity.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblZeroVelocity : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bZeroLinearVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bZeroAngularVelocity;
    
public:
    UAblZeroVelocity();
};

