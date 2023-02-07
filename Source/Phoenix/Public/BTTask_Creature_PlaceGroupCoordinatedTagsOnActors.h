#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TagPlacementOrder.h"
#include "BTTask_Creature_PlaceGroupCoordinatedTagsOnActors.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_PlaceGroupCoordinatedTagsOnActors : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTagPlacementOrder> AllOrders;
    
    UBTTask_Creature_PlaceGroupCoordinatedTagsOnActors();
};

