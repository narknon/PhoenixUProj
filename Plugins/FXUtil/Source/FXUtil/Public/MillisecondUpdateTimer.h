#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MillisecondUpdateTimer.generated.h"

USTRUCT(BlueprintType)
struct FMillisecondUpdateTimer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDateTime NextUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateRateMS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    FXUTIL_API FMillisecondUpdateTimer();
};

