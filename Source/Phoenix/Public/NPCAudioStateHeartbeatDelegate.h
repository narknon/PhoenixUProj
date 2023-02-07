#pragma once
#include "CoreMinimal.h"
#include "ENPC_AudioState.h"
#include "NPCAudioStateHeartbeatDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPCAudioStateHeartbeat, ENPC_AudioState, State);

