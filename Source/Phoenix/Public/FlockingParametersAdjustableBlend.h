#pragma once
#include "CoreMinimal.h"
#include "FlockingParametersAdjustable.h"
#include "FlockingParametersAdjustableBlend.generated.h"

USTRUCT(BlueprintType)
struct FFlockingParametersAdjustableBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFlockingParametersAdjustable Start;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFlockingParametersAdjustable End;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendTimeSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Age;
    
    PHOENIX_API FFlockingParametersAdjustableBlend();
};

