#pragma once
#include "CoreMinimal.h"
#include "ESkinFXAutoTriggerDelegateEvent.h"
#include "SkinFXAutoTriggerDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSkinFXAutoTriggerDelegate, AActor*, AffectedActor, FName, SkinFXFXName, ESkinFXAutoTriggerDelegateEvent, Event);

