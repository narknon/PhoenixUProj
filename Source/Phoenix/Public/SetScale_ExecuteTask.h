#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExecuteTask.h"
#include "SetScale_ExecuteTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USetScale_ExecuteTask : public UExecuteTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector mNewScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsRelative;
    
    USetScale_ExecuteTask();
};

