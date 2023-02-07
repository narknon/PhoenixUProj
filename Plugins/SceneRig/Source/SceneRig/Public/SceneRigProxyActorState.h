#pragma once
#include "CoreMinimal.h"
#include "TimeRigElementState.h"
#include "TimeRigParentElement.h"
#include "SceneRigBakeSequence.h"
#include "SceneRigProxyActorState.generated.h"

class UObject;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigProxyActorState : public UTimeRigElementState, public ISceneRigBakeSequence, public ITimeRigParentElement {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> ActionObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FloorContactPreviouslyEnabled;
    
    USceneRigProxyActorState();
    
    // Fix for true pure virtual functions not being implemented
};

