#pragma once
#include "CoreMinimal.h"
#include "LinearizedPathSplineAux.generated.h"

USTRUCT(BlueprintType)
struct FLinearizedPathSplineAux {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BorderIndex[2];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float BorderExtent[2];
    
    PATHRUNTIME_API FLinearizedPathSplineAux();
};

