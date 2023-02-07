#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTDecorator_IsPlayingAbility.generated.h"

UCLASS(Blueprintable)
class ABLECORE_API UBTDecorator_IsPlayingAbility : public UBTDecorator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector ActorToCheck;
    
public:
    UBTDecorator_IsPlayingAbility();
};

