#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_WalkToStation.generated.h"

class UObject;

UCLASS(Blueprintable)
class USceneActionState_WalkToStation : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    USceneActionState_WalkToStation();
    UFUNCTION(BlueprintCallable)
    void OnArrived(const UObject* InCaller);
    
};

