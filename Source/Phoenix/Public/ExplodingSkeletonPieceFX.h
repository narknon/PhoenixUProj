#pragma once
#include "CoreMinimal.h"
#include "ExplodingSkeletonPieceFXBase.h"
#include "ExplodingSkeletonPieceFX.generated.h"

USTRUCT(BlueprintType)
struct FExplodingSkeletonPieceFX : public FExplodingSkeletonPieceFXBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitForActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillOnStartFade;
    
    PHOENIX_API FExplodingSkeletonPieceFX();
};

