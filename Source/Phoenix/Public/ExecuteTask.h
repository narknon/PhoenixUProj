#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ExecuteTask.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UExecuteTask : public UObject {
    GENERATED_BODY()
public:
    UExecuteTask();
};

