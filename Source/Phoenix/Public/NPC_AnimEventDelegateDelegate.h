#pragma once
#include "CoreMinimal.h"
#include "NPC_AnimEventDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPC_AnimEventDelegate, FName, Name);

