#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesColor.h"
#include "LerpVolumesInteger.h"
#include "LerpVolumesScalar.h"
#include "LerpVolumesTag.h"
#include "LerpVolumesUnitDirection.h"
#include "LerpVolumesVector.h"
#include "LerpVolumesInterpolants.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesInterpolants {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FLerpVolumesScalar> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FLerpVolumesInteger> Integers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FLerpVolumesVector> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FLerpVolumesUnitDirection> Directions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FLerpVolumesColor> Colors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FLerpVolumesTag> Tags;
    
    LERPVOLUMES_API FLerpVolumesInterpolants();
};

