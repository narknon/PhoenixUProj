#pragma once
#include "CoreMinimal.h"
#include "LinearizedPathBorderPoint.h"
#include "LinearizedPathSplineAux.h"
#include "LinearizedSpline.h"
#include "LinearizedPath.generated.h"

USTRUCT(BlueprintType)
struct PATHRUNTIME_API FLinearizedPath : public FLinearizedSpline {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinearizedPathSplineAux> PathPointAux;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinearizedPathBorderPoint> NegBorderPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinearizedPathBorderPoint> PosBorderPoints;
    
public:
    FLinearizedPath();
};

