#pragma once
#include "CoreMinimal.h"
#include "EFixedSunPositionInputType.h"
#include "FixedSunPositionInput.generated.h"

USTRUCT(BlueprintType)
struct FFixedSunPositionInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Altitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFixedSunPositionInputType Type;
    
    DAYNIGHT_API FFixedSunPositionInput();
};

