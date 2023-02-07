#pragma once
#include "CoreMinimal.h"
#include "FXUpdate.h"
#include "FXUpdate_EndWhenMovementStops.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_EndWhenMovementStops : public UFXUpdate {
    GENERATED_BODY()
public:
    UFXUpdate_EndWhenMovementStops();
    UFUNCTION(BlueprintCallable)
    void MovementStopped(AActor* InActor);
    
};

