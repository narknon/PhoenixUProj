#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MilkyWayCorrection.generated.h"

USTRUCT(BlueprintType)
struct FMilkyWayCorrection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Rotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VCorrect;
    
    DAYNIGHT_API FMilkyWayCorrection();
};

