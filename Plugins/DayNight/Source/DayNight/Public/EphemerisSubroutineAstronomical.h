#pragma once
#include "CoreMinimal.h"
#include "EphemerisSubroutine.h"
#include "EphemerisSubroutineAstronomical.generated.h"

UCLASS(Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineAstronomical : public UEphemerisSubroutine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoonPeriodDays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverride_MoonPeriodDays;
    
    UEphemerisSubroutineAstronomical();
};

