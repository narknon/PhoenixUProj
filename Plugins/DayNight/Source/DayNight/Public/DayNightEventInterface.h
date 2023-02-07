#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Interface.h"
#include "EDayNightEventDirection.h"
#include "EMoonPhaseName.h"
#include "SolarNormalizedTime.h"
#include "DayNightEventInterface.generated.h"

class UDayNightMasterComponent;

UINTERFACE(Blueprintable)
class DAYNIGHT_API UDayNightEventInterface : public UInterface {
    GENERATED_BODY()
};

class DAYNIGHT_API IDayNightEventInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DayNightSunEvent(UDayNightMasterComponent* DayNightMaster, FName EventName, FSolarNormalizedTime NormalizedTime, FDateTime GameTime, EDayNightEventDirection SunDirection, float SunAltitudeDegrees, bool bLate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DayNightMoonEvent(UDayNightMasterComponent* DayNightMaster, FName EventName, FSolarNormalizedTime NormalizedTime, FDateTime GameTime, EDayNightEventDirection MoonDirection, float MoonAltitudeDegrees, EMoonPhaseName Phase, bool bLate);
    
};

