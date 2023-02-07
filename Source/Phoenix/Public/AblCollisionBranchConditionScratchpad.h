#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "AblCollisionBranchConditionScratchpad.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class UAblCollisionBranchConditionScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UAblCollisionBranchConditionScratchpad();
    UFUNCTION(BlueprintCallable)
    void HandleActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
};

