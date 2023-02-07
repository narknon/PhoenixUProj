#pragma once
#include "CoreMinimal.h"
#include "AzimuthAltitudeDegrees.generated.h"

USTRUCT(BlueprintType)
struct FAzimuthAltitudeDegrees {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AzimuthDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AltitudeDegrees;
    
    DAYNIGHT_API FAzimuthAltitudeDegrees();
};

