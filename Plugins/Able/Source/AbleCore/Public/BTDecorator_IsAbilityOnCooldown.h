#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Templates/SubclassOf.h"
#include "BTDecorator_IsAbilityOnCooldown.generated.h"

class UAblAbility;

UCLASS(Blueprintable)
class ABLECORE_API UBTDecorator_IsAbilityOnCooldown : public UBTDecorator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector ActorToCheck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> Ability;
    
public:
    UBTDecorator_IsAbilityOnCooldown();
};

