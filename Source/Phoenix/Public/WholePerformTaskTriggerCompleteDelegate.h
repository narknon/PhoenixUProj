#pragma once
#include "CoreMinimal.h"
#include "WholePerformTaskTriggerCompleteDelegate.generated.h"

class APerformTasksForAI;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWholePerformTaskTriggerComplete, const APerformTasksForAI*, InPerformTasksForAI);

