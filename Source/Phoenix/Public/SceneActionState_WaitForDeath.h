#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_WaitForDeath.generated.h"

class AActor;

UCLASS(Blueprintable)
class PHOENIX_API USceneActionState_WaitForDeath : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    USceneActionState_WaitForDeath();
    UFUNCTION(BlueprintCallable)
    void OnActorEndPlay(AActor* Actor);
    
};

