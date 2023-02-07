#pragma once
#include "CoreMinimal.h"
#include "Mercuna3DMovementAccelerations.generated.h"

USTRUCT(BlueprintType)
struct FMercuna3DMovementAccelerations {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Forward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Backward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Sideways;
    
    MERCUNA3DMOVEMENT_API FMercuna3DMovementAccelerations();
};

