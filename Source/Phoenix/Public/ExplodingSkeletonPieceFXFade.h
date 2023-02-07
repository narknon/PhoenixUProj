#pragma once
#include "CoreMinimal.h"
#include "ExplodingSkeletonPieceFXBase.h"
#include "ExplodingSkeletonPieceFXFade.generated.h"

USTRUCT(BlueprintType)
struct FExplodingSkeletonPieceFXFade : public FExplodingSkeletonPieceFXBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitForSystemToFinish;
    
    PHOENIX_API FExplodingSkeletonPieceFXFade();
};

