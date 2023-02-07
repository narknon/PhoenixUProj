#pragma once
#include "CoreMinimal.h"
#include "OnDialogueLineAnimFinishedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDialogueLineAnimFinished, bool, bCancelled);

