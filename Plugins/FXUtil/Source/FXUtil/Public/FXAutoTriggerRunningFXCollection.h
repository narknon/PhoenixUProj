#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRunningFXGroup.h"
#include "FXAutoTriggerRunningFXList.h"
#include "FXAutoTriggerRunningFXCollection.generated.h"

class UFXAutoTriggerGlobalDefinitionAsset;

USTRUCT(BlueprintType)
struct FFXAutoTriggerRunningFXCollection : public FFXAutoTriggerRunningFXList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerGlobalDefinitionAsset* Globals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FFXAutoTriggerRunningFXGroup> Groups;
    
    FXUTIL_API FFXAutoTriggerRunningFXCollection();
};

