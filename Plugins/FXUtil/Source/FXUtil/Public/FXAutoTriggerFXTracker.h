#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerFXTrackerEntry.h"
#include "FXAutoTriggerFXTracker.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FFXAutoTriggerFXTracker {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FFXAutoTriggerFXTrackerEntry> FXMap;
    
    FXUTIL_API FFXAutoTriggerFXTracker();
};

