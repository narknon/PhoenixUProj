#pragma once
#include "CoreMinimal.h"
#include "MasterTickThrottlerSettingsAdvanced.generated.h"

USTRUCT(BlueprintType)
struct MASTERTICKTHROTTLER_API FMasterTickThrottlerSettingsAdvanced {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseXYDistance: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bResponsiveIntervalChanges: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bThrottleInEditor: 1;
    
    FMasterTickThrottlerSettingsAdvanced();
};

