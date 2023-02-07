#pragma once
#include "CoreMinimal.h"
#include "StatsComponentReportSettings.generated.h"

USTRUCT(BlueprintType)
struct FStatsComponentReportSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> Args;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 TotalReports;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 FrameDelay;
    
    WORLDFX_API FStatsComponentReportSettings();
};

