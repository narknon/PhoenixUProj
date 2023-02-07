#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAnimMechanicType.h"
#include "AblSetAnimMechanicTypeTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetAnimMechanicTypeTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAnimMechanicType::Type> AnimMechanicType;
    
public:
    UAblSetAnimMechanicTypeTask();
};

