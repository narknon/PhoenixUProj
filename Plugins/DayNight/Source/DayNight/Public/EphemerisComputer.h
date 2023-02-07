#pragma once
#include "CoreMinimal.h"
#include "EphemerisDayInfo.h"
#include "EphemerisComputer.generated.h"

class UEphemerisBasis;
class UEphemerisSubroutine;
class UObject;

USTRUCT(BlueprintType)
struct DAYNIGHT_API FEphemerisComputer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEphemerisDayInfo AstronomicalDayInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEphemerisDayInfo DayInfo;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEphemerisBasis* Basis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UEphemerisSubroutine*, UObject*> SubroutineData;
    
public:
    FEphemerisComputer();
};

