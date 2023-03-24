#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RaceGhostOrb.generated.h"

UCLASS(Blueprintable)
class ARaceGhostOrb : public AActor {
    GENERATED_BODY()
public:
    ARaceGhostOrb(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishedCourse();
    
};

