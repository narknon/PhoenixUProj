#pragma once
#include "CoreMinimal.h"
#include "ClothMountTargets.generated.h"

class UTransformProvider;

USTRUCT(BlueprintType)
struct FClothMountTargets {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* RightClothTargetTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* HipsClothTargetTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* LeftClothTargetTransform;
    
    PHOENIX_API FClothMountTargets();
};

