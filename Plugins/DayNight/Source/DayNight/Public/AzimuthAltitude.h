#pragma once
#include "CoreMinimal.h"
#include "AzimuthAltitude.generated.h"

USTRUCT(BlueprintType)
struct FAzimuthAltitude {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Azimuth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Altitude;
    
    DAYNIGHT_API FAzimuthAltitude();
};

