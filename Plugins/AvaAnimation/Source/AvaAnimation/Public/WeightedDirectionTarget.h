#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeightedDirectionTarget.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FWeightedDirectionTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetInWorldSpace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    FWeightedDirectionTarget();
};

