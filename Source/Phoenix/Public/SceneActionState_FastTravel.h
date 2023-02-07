#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_FastTravel.generated.h"

UCLASS(Blueprintable)
class USceneActionState_FastTravel : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    USceneActionState_FastTravel();
    UFUNCTION(BlueprintCallable)
    void OnArrived();
    
};

