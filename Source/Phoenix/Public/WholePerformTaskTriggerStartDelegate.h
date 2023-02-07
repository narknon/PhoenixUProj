#pragma once
#include "CoreMinimal.h"
#include "WholePerformTaskTriggerStartDelegate.generated.h"

class APerformTasksForAI;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWholePerformTaskTriggerStart, const APerformTasksForAI*, InPerformTasksForAI);

