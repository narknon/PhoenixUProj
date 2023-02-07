#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MasterTickThrottlerSettings.h"
#include "MasterTickThrottlerTracker.generated.h"

USTRUCT(BlueprintType)
struct MASTERTICKTHROTTLER_API FMasterTickThrottlerTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMasterTickThrottlerSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime LastKeepAlive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDisableThrottling: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bHasKeepAliveInterface: 1;
    
    FMasterTickThrottlerTracker();
};

