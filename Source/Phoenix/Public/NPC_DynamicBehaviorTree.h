#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NPC_DynamicBehaviorTree.generated.h"

class UBehaviorTree;

USTRUCT(BlueprintType)
struct FNPC_DynamicBehaviorTree {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* BehaviorTree;
    
    PHOENIX_API FNPC_DynamicBehaviorTree();
};

