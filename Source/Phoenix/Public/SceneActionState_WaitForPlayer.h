#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_WaitForPlayer.generated.h"

class UScheduledEntity;

UCLASS(Blueprintable)
class USceneActionState_WaitForPlayer : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    USceneActionState_WaitForPlayer();
    UFUNCTION(BlueprintCallable)
    void OnPerformTaskComplete(UScheduledEntity* InScheduledEntity, int32 ActivityTypeBits);
    
};

