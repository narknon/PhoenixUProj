#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "EphemerisSubroutineGamifyTime.h"
#include "EphemerisSubroutineGamifyTimeCurveBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineGamifyTimeCurveBase : public UEphemerisSubroutineGamifyTime {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve ToNormalizedTime;
    
    UEphemerisSubroutineGamifyTimeCurveBase();
};

