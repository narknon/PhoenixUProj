#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ECreatureFlightState.h"
#include "BTTask_Creature_SetDesiredFlightState.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_SetDesiredFlightState : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureFlightState FlightState;
    
    UBTTask_Creature_SetDesiredFlightState();
};

