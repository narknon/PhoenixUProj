#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "ECreatureGroupCoordinationTagTypesToRemove.h"
#include "BTTask_Creature_RemoveGroupCoordinatedTagsOfOwnerWithID.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_RemoveGroupCoordinatedTagsOfOwnerWithID : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECreatureGroupCoordinationTagTypesToRemove> TagType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector OwnerBlackboardKey;
    
    UBTTask_Creature_RemoveGroupCoordinatedTagsOfOwnerWithID();
};

