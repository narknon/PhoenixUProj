#pragma once
#include "CoreMinimal.h"
#include "PathExtent.generated.h"

USTRUCT(BlueprintType)
struct PATHRUNTIME_API FPathExtent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Neg;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Pos;
    
    FPathExtent();
};

