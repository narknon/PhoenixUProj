#pragma once
#include "CoreMinimal.h"
#include "BoneReferenceEx.h"
#include "EQuadrupedSpineChainType.h"
#include "QuadrupedSpineBoneChain.generated.h"

USTRUCT(BlueprintType)
struct FQuadrupedSpineBoneChain {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuadrupedSpineChainType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoneReferenceEx StartBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoneReferenceEx EndBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    PHOENIX_API FQuadrupedSpineBoneChain();
};

