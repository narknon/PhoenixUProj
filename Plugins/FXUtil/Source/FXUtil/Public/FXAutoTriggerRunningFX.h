#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerFXTracker.h"
#include "FXAutoTriggerRunningFX.generated.h"

class UFXAutoTriggerDefinitionAsset;
class UObject;

USTRUCT(BlueprintType)
struct FFXAutoTriggerRunningFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerDefinitionAsset* Asset;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FFXAutoTriggerFXTracker Tracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bMeetsPrerequisite;
    
    FXUTIL_API FFXAutoTriggerRunningFX();
};

