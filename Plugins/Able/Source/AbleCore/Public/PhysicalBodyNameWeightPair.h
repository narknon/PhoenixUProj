#pragma once
#include "CoreMinimal.h"
#include "PhysicalBodyNameWeightPair.generated.h"

USTRUCT(BlueprintType)
struct FPhysicalBodyNameWeightPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoneWeight;
    
    ABLECORE_API FPhysicalBodyNameWeightPair();
};

