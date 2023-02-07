#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ECreatureStance.h"
#include "BTTask_Creature_SetStance.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_SetStance : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureStance Stance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWait;
    
    UBTTask_Creature_SetStance();
};

