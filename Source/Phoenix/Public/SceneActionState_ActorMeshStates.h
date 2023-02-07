#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_ActorMeshStates.generated.h"

UCLASS(Blueprintable)
class USceneActionState_ActorMeshStates : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bNeedsRestore;
    
    USceneActionState_ActorMeshStates();
};

