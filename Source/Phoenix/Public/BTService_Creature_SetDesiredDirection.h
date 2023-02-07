#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTService_Creature_SetDesiredDirection.generated.h"

UCLASS(Blueprintable)
class UBTService_Creature_SetDesiredDirection : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetActorOrLocationKey;
    
    UBTService_Creature_SetDesiredDirection();
};

