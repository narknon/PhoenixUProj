#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingSunColorParams.h"
#include "GlobalLightingGenerateSunColorCurve.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightingGenerateSunColorCurve : public FGlobalLightingSunColorParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunAngleStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunAngleEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunAngleIncrement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ErrorTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCubic;
    
    GLOBALLIGHTRIG_API FGlobalLightingGenerateSunColorCurve();
};

