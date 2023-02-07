#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_Creature_RemoveGroupCoordinatedTagsFromActor.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_RemoveGroupCoordinatedTagsFromActor : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> TagIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector ActorBlackboardKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustBeOwnedBySelf;
    
    UBTTask_Creature_RemoveGroupCoordinatedTagsFromActor();
};

