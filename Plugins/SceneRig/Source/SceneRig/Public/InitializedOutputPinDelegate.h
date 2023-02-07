#pragma once
#include "CoreMinimal.h"
#include "InitializedOutputPinDelegate.generated.h"

class USceneRigPlayer;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInitializedOutputPin, USceneRigPlayer*, SceneRigPlayer);

