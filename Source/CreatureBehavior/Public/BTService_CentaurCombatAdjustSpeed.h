#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTService_CentaurCombatAdjustSpeed.generated.h"

UCLASS(Blueprintable)
class UBTService_CentaurCombatAdjustSpeed : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector MoveToLocationKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JogSprintDistanceThreshold;
    
    UBTService_CentaurCombatAdjustSpeed();
};

