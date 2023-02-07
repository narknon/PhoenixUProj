#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LinearizedSplinePoint.generated.h"

USTRUCT(BlueprintType)
struct PATHRUNTIME_API FLinearizedSplinePoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TangentOffset;
    
    FLinearizedSplinePoint();
};

