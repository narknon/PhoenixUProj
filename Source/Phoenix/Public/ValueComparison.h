#pragma once
#include "CoreMinimal.h"
#include "EValueComparison.h"
#include "ValueComparison.generated.h"

USTRUCT(BlueprintType)
struct FValueComparison {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EValueComparison ComparisonOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ComparisonValue;
    
    PHOENIX_API FValueComparison();
};

