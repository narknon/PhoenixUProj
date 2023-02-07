#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "AblDieOnNextImpactReactionScratchpad.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class UAblDieOnNextImpactReactionScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UAblDieOnNextImpactReactionScratchpad();
    UFUNCTION(BlueprintCallable)
    void HandleActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
};

