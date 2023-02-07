#pragma once
#include "CoreMinimal.h"
#include "DateInput.h"
#include "EphemerisSubroutine.h"
#include "EphemerisSubroutineFauxMoon.generated.h"

UCLASS(Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineFauxMoon : public UEphemerisSubroutine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateInput IdealDate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseOffsetDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetVarianceDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetPeriodDays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhasePeriodDays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverride_PhasePeriodDays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseIdealDate;
    
    UEphemerisSubroutineFauxMoon();
};

