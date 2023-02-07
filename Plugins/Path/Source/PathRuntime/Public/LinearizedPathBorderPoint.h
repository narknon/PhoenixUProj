#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LinearizedPathBorderPoint.generated.h"

USTRUCT(BlueprintType)
struct FLinearizedPathBorderPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FirstSplineIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LastSplineIndex;
    
    PATHRUNTIME_API FLinearizedPathBorderPoint();
};

