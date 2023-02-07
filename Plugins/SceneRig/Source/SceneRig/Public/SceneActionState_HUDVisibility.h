#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_HUDVisibility.generated.h"

class UTimeRigElementState;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_HUDVisibility : public USceneRigActionState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UTimeRigElementState*> ElementStatesNotReadyToPlay;
    
public:
    USceneActionState_HUDVisibility();
};

