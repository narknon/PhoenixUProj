#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DayNightEventSystemLastState.generated.h"

USTRUCT(BlueprintType)
struct FDayNightEventSystemLastState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDateTime DateTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float SunAltitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MoonAltitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bFirstRun;
    
    DAYNIGHT_API FDayNightEventSystemLastState();
};

