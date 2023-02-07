#pragma once
#include "CoreMinimal.h"
#include "OdcGeometryMetrics.generated.h"

USTRUCT(BlueprintType)
struct FOdcGeometryMetrics {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceLedgeRadius;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceLedgeIntoWallAdjust;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceLedgeUpAdjust;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceLedgeDownCast;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LinkOffsetFromLadderEnds;
    
    ODYSSEYRUNTIME_API FOdcGeometryMetrics();
};

