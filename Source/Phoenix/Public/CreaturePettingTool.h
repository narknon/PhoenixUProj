#pragma once
#include "CoreMinimal.h"
#include "CreatureInteractionTool.h"
#include "CreaturePettingTool.generated.h"

UCLASS(Blueprintable)
class ACreaturePettingTool : public ACreatureInteractionTool {
    GENERATED_BODY()
public:
    ACreaturePettingTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RemoveAimAtTarget();
    
    UFUNCTION(BlueprintCallable)
    void AddAimAtTarget();
    
};

