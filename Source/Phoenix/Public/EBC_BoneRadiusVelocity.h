#pragma once
#include "CoreMinimal.h"
#include "EBC_BoneRadiusVelocity.generated.h"

USTRUCT(BlueprintType)
struct FEBC_BoneRadiusVelocity {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Bone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float orbitRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float orbitVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LinearVelocity;
    
    PHOENIX_API FEBC_BoneRadiusVelocity();
};

