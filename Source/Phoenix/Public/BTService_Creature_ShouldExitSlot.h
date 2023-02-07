#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTService_Creature_ShouldExitSlot.generated.h"

UCLASS(Blueprintable)
class UBTService_Creature_ShouldExitSlot : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector BlackboardKey;
    
    UBTService_Creature_ShouldExitSlot();
};

