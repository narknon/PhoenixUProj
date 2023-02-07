#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CapsuleBoundingSphere.generated.h"

USTRUCT(BlueprintType)
struct FCapsuleBoundingSphere {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Center;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValid;
    
    PHOENIX_API FCapsuleBoundingSphere();
};

