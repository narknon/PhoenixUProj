#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DistanceFogDayNight.generated.h"

USTRUCT(BlueprintType)
struct FDistanceFogDayNight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SunDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NightDay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoonBrightness;
    
    RENDERSETTINGS_API FDistanceFogDayNight();
};

