#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "NavigationDisruptor.generated.h"

class AActor;

UCLASS(Blueprintable)
class PHOENIX_API ANavigationDisruptor : public ATriggerBox {
    GENERATED_BODY()
public:
    ANavigationDisruptor();
protected:
    UFUNCTION(BlueprintCallable)
    void OnEndActorOverlap(AActor* SelfActor, AActor* Other);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginActorOverlap(AActor* SelfActor, AActor* Other);
    
};

