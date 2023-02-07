#pragma once
#include "CoreMinimal.h"
#include "NPCWasPerceivedByPlayerDelegate.generated.h"

class ANPC_Character;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPCWasPerceivedByPlayer, ANPC_Character*, NPCChar);

