#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WindAffectedScale.generated.h"

USTRUCT(BlueprintType)
struct WIND_API FWindAffectedScale {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ScaleMinMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D WindSpeedMinMax;
    
    FWindAffectedScale();
};

