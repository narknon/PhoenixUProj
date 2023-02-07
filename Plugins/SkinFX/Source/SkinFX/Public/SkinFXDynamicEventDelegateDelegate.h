#pragma once
#include "CoreMinimal.h"
#include "ESkinFXDelegateEvent.h"
#include "SkinFXDynamicEventDelegateDelegate.generated.h"

class USkinFXComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSkinFXDynamicEventDelegate, USkinFXComponent*, SkinFXComponent, FName, FXName, ESkinFXDelegateEvent, Event);

