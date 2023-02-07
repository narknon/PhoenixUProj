#pragma once
#include "CoreMinimal.h"
#include "TimeRigParentElement.h"
#include "SceneRigActionState.h"
#include "SceneActionState_Unskippable.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_Unskippable : public USceneRigActionState, public ITimeRigParentElement {
    GENERATED_BODY()
public:
    USceneActionState_Unskippable();
    
    // Fix for true pure virtual functions not being implemented
};

