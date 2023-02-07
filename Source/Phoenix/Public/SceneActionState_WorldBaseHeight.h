#pragma once
#include "CoreMinimal.h"
#include "WorldBaseHeightInterface.h"
#include "SceneRigActionState.h"
#include "SceneActionState_WorldBaseHeight.generated.h"

UCLASS(Blueprintable)
class USceneActionState_WorldBaseHeight : public USceneRigActionState, public IWorldBaseHeightInterface {
    GENERATED_BODY()
public:
    USceneActionState_WorldBaseHeight();
    
    // Fix for true pure virtual functions not being implemented
};

