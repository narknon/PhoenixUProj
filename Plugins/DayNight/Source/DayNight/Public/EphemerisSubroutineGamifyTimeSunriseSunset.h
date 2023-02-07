#pragma once
#include "CoreMinimal.h"
#include "EphemerisSubroutineGamifyTimeCurveBase.h"
#include "TimeInput.h"
#include "EphemerisSubroutineGamifyTimeSunriseSunset.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineGamifyTimeSunriseSunset : public UEphemerisSubroutineGamifyTimeCurveBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput SunRise;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput SunSet;
    
    UEphemerisSubroutineGamifyTimeSunriseSunset();
};

