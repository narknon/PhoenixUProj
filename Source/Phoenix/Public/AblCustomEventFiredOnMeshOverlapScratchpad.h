#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "Engine/EngineTypes.h"
#include "AblCustomEventFiredOnMeshOverlapScratchpad.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable, NonTransient)
class UAblCustomEventFiredOnMeshOverlapScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UAblCustomEventFiredOnMeshOverlapScratchpad();
    UFUNCTION(BlueprintCallable)
    void HandleOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

