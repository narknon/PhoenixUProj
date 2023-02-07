#pragma once
#include "CoreMinimal.h"
#include "FluidSimParams.h"
#include "CompiledFluidSimParams.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FCompiledFluidSimParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FFluidSimParams Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* ColorMap;
    
    FLUIDSIM_API FCompiledFluidSimParams();
};

