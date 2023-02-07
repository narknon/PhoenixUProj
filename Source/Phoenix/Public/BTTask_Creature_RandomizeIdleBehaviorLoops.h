#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Creature_RandomizeIdleBehaviorLoops.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_RandomizeIdleBehaviorLoops : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAdjustForTimeOfDayIfWild;
    
    UBTTask_Creature_RandomizeIdleBehaviorLoops();
};

