#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomEncounterActor.generated.h"

UCLASS(Blueprintable)
class ARandomEncounterActor : public AActor {
    GENERATED_BODY()
public:
    ARandomEncounterActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool IsActive();
    
    UFUNCTION(BlueprintCallable)
    void ForceDeactivate();
    
    UFUNCTION(BlueprintCallable)
    void ForceActivate();
    
};

