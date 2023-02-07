#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblEnemyMaintainVelocityTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblEnemyMaintainVelocityTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Gravity;
    
public:
    UAblEnemyMaintainVelocityTask();
};

