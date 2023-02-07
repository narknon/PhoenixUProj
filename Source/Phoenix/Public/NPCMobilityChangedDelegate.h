#pragma once
#include "CoreMinimal.h"
#include "ENPC_Mobility.h"
#include "NPCMobilityChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPCMobilityChanged, ENPC_Mobility, Mobility);

