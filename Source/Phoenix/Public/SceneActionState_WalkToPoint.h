#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_WalkToPoint.generated.h"

UCLASS(Blueprintable)
class USceneActionState_WalkToPoint : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    USceneActionState_WalkToPoint();
    UFUNCTION(BlueprintCallable)
    void OnArrived();
    
};

