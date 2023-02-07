#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblMountRiderAbleEventTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblMountRiderAbleEventTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
public:
    UAblMountRiderAbleEventTask();
};

