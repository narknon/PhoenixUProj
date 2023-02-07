#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesInterpolantPCs.h"
#include "LerpVolumesInteger.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesInteger : public FLerpVolumesInterpolantPCs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bClampMinValue: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bClampMaxValue: 1;
    
    LERPVOLUMES_API FLerpVolumesInteger();
};

