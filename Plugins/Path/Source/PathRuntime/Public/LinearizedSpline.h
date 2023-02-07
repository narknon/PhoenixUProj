#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LinearizedSplinePoint.h"
#include "LinearizedSpline.generated.h"

USTRUCT(BlueprintType)
struct PATHRUNTIME_API FLinearizedSpline {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsLooped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinearizedSplinePoint> SplinePoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Length;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox Bounds;
    
public:
    FLinearizedSpline();
};

