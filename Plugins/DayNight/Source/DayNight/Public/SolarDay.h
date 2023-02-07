#pragma once
#include "CoreMinimal.h"
#include "Curves/RichCurve.h"
#include "EphemerisDayInfo.h"
#include "SolarDay.generated.h"

USTRUCT(BlueprintType)
struct FSolarDay {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEphemerisDayInfo DayInfo;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve AzimuthCurve;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve AltitudeCurve;
    
    DAYNIGHT_API FSolarDay();
};

