#pragma once
#include "CoreMinimal.h"
#include "NPCAbilityFinishedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPCAbilityFinished, uint8, AIAction);

