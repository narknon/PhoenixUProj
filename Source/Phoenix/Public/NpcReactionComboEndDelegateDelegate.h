#pragma once
#include "CoreMinimal.h"
#include "NpcReactionComboEndDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNpcReactionComboEndDelegate, int32, ComboCount);

