#pragma once
#include "CoreMinimal.h"
#include "ENPC_Event.h"
#include "NPCEventDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPCEventDelegate, ENPC_Event, Event);

