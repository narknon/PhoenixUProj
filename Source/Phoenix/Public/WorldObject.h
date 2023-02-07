#pragma once
#include "CoreMinimal.h"
#include "EInteractiveState.h"
#include "InteractiveObjectActor.h"
#include "WorldObject.generated.h"

UCLASS(Blueprintable)
class AWorldObject : public AInteractiveObjectActor {
    GENERATED_BODY()
public:
    AWorldObject();
protected:
    UFUNCTION(BlueprintCallable)
    bool TryCreateBeacon();
    
    UFUNCTION(BlueprintCallable)
    void OnAboutToSaveGame();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyCurrentState(const EInteractiveState CurrentObjectState);
    
};

