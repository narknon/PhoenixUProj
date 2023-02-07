#pragma once
#include "CoreMinimal.h"
#include "CapsuleBoundingSphere.h"
#include "CapsuleBoundingSphereGroup.generated.h"

USTRUCT(BlueprintType)
struct FCapsuleBoundingSphereGroup {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCapsuleBoundingSphere> Spheres;
    
public:
    PHOENIX_API FCapsuleBoundingSphereGroup();
};

