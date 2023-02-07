#pragma once
#include "CoreMinimal.h"
#include "NPCPerceivePlayerDelegate.generated.h"

class ANPC_Character;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPCPerceivePlayer, ANPC_Character*, NPCChar);

