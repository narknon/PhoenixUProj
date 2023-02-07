#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_CharacterWalkBase.generated.h"

UCLASS(Abstract, Blueprintable)
class USceneActionState_CharacterWalkBase : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    USceneActionState_CharacterWalkBase();
    UFUNCTION(BlueprintCallable)
    void Arrived();
    
};

