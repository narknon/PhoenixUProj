#pragma once
#include "CoreMinimal.h"
#include "Mercuna3DMovementWorldAccelerations.generated.h"

USTRUCT(BlueprintType)
struct FMercuna3DMovementWorldAccelerations {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Upward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Downward;
    
    MERCUNA3DMOVEMENT_API FMercuna3DMovementWorldAccelerations();
};

