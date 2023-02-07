#pragma once
#include "CoreMinimal.h"
#include "TimeRigEventWithActorDynamicDelegateDelegate.generated.h"

class ASceneRigActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FTimeRigEventWithActorDynamicDelegate, ASceneRigActor*, SceneRigActor);

