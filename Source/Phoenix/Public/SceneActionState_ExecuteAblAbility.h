#pragma once
#include "CoreMinimal.h"
#include "SceneRigBakeSequence.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_ExecuteAblAbility.generated.h"

UCLASS(Blueprintable)
class USceneActionState_ExecuteAblAbility : public USceneRigObjectActionState, public ISceneRigBakeSequence {
    GENERATED_BODY()
public:
    USceneActionState_ExecuteAblAbility();
    
    // Fix for true pure virtual functions not being implemented
};

