#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "EphemerisDayInfo.h"
#include "EphemerisSubroutineIdealSunPathPreview.generated.h"

USTRUCT(BlueprintType)
struct FEphemerisSubroutineIdealSunPathPreview {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEphemerisDayInfo DayInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve AzimuthCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve AltitudeCurve;
    
    DAYNIGHT_API FEphemerisSubroutineIdealSunPathPreview();
};

