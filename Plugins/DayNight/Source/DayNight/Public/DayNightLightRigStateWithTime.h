#pragma once
#include "CoreMinimal.h"
#include "DayNightLightRigState.h"
#include "LightParameterSmoothingTime.h"
#include "DayNightLightRigStateWithTime.generated.h"

USTRUCT(BlueprintType)
struct FDayNightLightRigStateWithTime : public FDayNightLightRigState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightParameterSmoothingTime Time;
    
    DAYNIGHT_API FDayNightLightRigStateWithTime();
};

