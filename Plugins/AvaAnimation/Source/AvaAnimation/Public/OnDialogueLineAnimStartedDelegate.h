#pragma once
#include "CoreMinimal.h"
#include "OnDialogueLineAnimStartedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDialogueLineAnimStarted, FName, DialogueID, float, WorldTime);

