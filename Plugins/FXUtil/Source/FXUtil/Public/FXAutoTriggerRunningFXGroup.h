#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRunningFXList.h"
#include "FXAutoTriggerRunningFXGroup.generated.h"

class UFXAutoTriggerGroupDefinitionAsset;

USTRUCT(BlueprintType)
struct FFXAutoTriggerRunningFXGroup : public FFXAutoTriggerRunningFXList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerGroupDefinitionAsset* Group;
    
    FXUTIL_API FFXAutoTriggerRunningFXGroup();
};

