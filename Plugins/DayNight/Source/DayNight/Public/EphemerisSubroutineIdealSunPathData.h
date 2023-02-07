#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SolarDay.h"
#include "EphemerisSubroutineIdealSunPathData.generated.h"

UCLASS(Blueprintable, Transient)
class DAYNIGHT_API UEphemerisSubroutineIdealSunPathData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSolarDay SolarDay;
    
    UEphemerisSubroutineIdealSunPathData();
};

