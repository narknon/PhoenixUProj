#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AttackCollisionType.h"
#include "ablAttackCollisionTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablAttackCollisionTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AttackCollisionType CollisionType;
    
    UablAttackCollisionTask();
};

