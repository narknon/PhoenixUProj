#pragma once
#include "CoreMinimal.h"
#include "CreatureInteractionTool.h"
#include "CreaturePettingTool.generated.h"

UCLASS(Blueprintable)
class ACreaturePettingTool : public ACreatureInteractionTool {
    GENERATED_BODY()
public:
    ACreaturePettingTool();
    UFUNCTION(BlueprintCallable)
    void RemoveAimAtTarget();
    
    UFUNCTION(BlueprintCallable)
    void AddAimAtTarget();
    
};

