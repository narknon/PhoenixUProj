#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_AbandonStations.generated.h"

UCLASS(Blueprintable)
class USceneActionState_AbandonStations : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    USceneActionState_AbandonStations();
    UFUNCTION(BlueprintCallable)
    void OnExited();
    
};

