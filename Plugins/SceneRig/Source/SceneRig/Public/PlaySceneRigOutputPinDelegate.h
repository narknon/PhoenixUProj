#pragma once
#include "CoreMinimal.h"
#include "PlaySceneRigOutputPinDelegate.generated.h"

class USceneRigPlayer;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlaySceneRigOutputPin, USceneRigPlayer*, SceneRigPlayer);

