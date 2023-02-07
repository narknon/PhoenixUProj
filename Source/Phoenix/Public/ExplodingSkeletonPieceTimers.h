#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExplodingSkeletonPieceTimers.generated.h"

USTRUCT(BlueprintType)
struct FExplodingSkeletonPieceTimers {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ActivationDelayMinMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D TimeoutMinMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D FadeOutMinMax;
    
    PHOENIX_API FExplodingSkeletonPieceTimers();
};

