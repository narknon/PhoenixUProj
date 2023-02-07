#pragma once
#include "CoreMinimal.h"
#include "MultiFX2Handle.h"
#include "FXAutoTriggerFXTrackerEntry.generated.h"

USTRUCT(BlueprintType)
struct FFXAutoTriggerFXTrackerEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMultiFX2Handle FXHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> DisableParameterUpdates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SleepFrames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Age;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 TouchedFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisableActorUpdates;
    
    FXUTIL_API FFXAutoTriggerFXTrackerEntry();
};

