#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FluidSimEmitterParams.generated.h"

USTRUCT(BlueprintType)
struct FFluidSimEmitterParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float EmitterMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FVector4 EmitterDir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float EmitterBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float MotionVectorStrength;
    
    FLUIDSIM_API FFluidSimEmitterParams();
};

