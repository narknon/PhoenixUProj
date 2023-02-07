#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesInterpolantPCs.h"
#include "LerpVolumesScalar.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesScalar : public FLerpVolumesInterpolantPCs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bClampMinValue: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bClampMaxValue: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bNormalizeValue: 1;
    
    LERPVOLUMES_API FLerpVolumesScalar();
};

