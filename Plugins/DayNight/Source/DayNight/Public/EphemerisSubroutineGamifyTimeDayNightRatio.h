#pragma once
#include "CoreMinimal.h"
#include "EphemerisSubroutineGamifyTimeCurveBase.h"
#include "EphemerisSubroutineGamifyTimeDayNightRatio.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineGamifyTimeDayNightRatio : public UEphemerisSubroutineGamifyTimeCurveBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DayToNightRatio;
    
    UEphemerisSubroutineGamifyTimeDayNightRatio();
};

