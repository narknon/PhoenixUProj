#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_PerformTaskFollowSpline.generated.h"

class UScheduledEntity;

UCLASS(Blueprintable)
class USceneActionState_PerformTaskFollowSpline : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    USceneActionState_PerformTaskFollowSpline();
    UFUNCTION(BlueprintCallable)
    void OnSplineCompleted(UScheduledEntity* InScheduledEntity, int32 ActivityTypeBits);
    
};

