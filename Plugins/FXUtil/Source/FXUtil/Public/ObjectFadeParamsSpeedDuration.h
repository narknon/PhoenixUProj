#pragma once
#include "CoreMinimal.h"
#include "EObjectFadeDirection.h"
#include "EObjectFadeSpeed.h"
#include "ObjectFadeParamsSpeedDuration.generated.h"

USTRUCT(BlueprintType)
struct FObjectFadeParamsSpeedDuration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EObjectFadeDirection Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EObjectFadeSpeed Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDuration;
    
    FXUTIL_API FObjectFadeParamsSpeedDuration();
};

