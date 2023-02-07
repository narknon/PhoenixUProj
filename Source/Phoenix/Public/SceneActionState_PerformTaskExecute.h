#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_PerformTaskExecute.generated.h"

class APerformTasksForAI;

UCLASS(Blueprintable)
class USceneActionState_PerformTaskExecute : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    USceneActionState_PerformTaskExecute();
    UFUNCTION(BlueprintCallable)
    void OnPTComplete(const APerformTasksForAI* InPTPtr);
    
};

