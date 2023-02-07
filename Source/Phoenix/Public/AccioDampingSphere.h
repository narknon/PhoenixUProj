#pragma once
#include "CoreMinimal.h"
#include "AccioDampingSphere.generated.h"

USTRUCT(BlueprintType)
struct FAccioDampingSphere {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LinearDamping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngularDamping;
    
    PHOENIX_API FAccioDampingSphere();
};

