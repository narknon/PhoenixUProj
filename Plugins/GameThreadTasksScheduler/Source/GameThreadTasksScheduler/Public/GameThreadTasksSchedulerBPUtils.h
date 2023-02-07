#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameThreadTasksSchedulerDynamicTaskDelegate.h"
#include "GameThreadTasksSchedulerBPUtils.generated.h"

UCLASS(Blueprintable)
class GAMETHREADTASKSSCHEDULER_API UGameThreadTasksSchedulerBPUtils : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UGameThreadTasksSchedulerBPUtils();
    UFUNCTION(BlueprintCallable)
    static void PushGameThreadTask(FGameThreadTasksSchedulerDynamicTask Runnable, int32 Priority, FName TaskName);
    
};

