#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AzimuthAltitude.h"
#include "AziAltTime.generated.h"

USTRUCT(BlueprintType)
struct FAziAltTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAzimuthAltitude AziAlt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime DateTime;
    
    DAYNIGHT_API FAziAltTime();
};

