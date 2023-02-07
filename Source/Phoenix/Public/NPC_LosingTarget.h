#pragma once
#include "CoreMinimal.h"
#include "ENPC_LosingTargetType.h"
#include "NPC_DynamicBehaviorTree.h"
#include "NPC_LosingTarget.generated.h"

USTRUCT(BlueprintType)
struct FNPC_LosingTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_LosingTargetType State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_DynamicBehaviorTree DynamicBehaviorTree;
    
    PHOENIX_API FNPC_LosingTarget();
};

