#pragma once
#include "CoreMinimal.h"
#include "NPCLostPerceivePlayerDelegate.generated.h"

class ANPC_Character;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPCLostPerceivePlayer, ANPC_Character*, NPCChar);

