#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Creature_WaitUntilStationary.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_WaitUntilStationary : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowAnimationTransition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowIdleVariation;
    
    UBTTask_Creature_WaitUntilStationary();
};

