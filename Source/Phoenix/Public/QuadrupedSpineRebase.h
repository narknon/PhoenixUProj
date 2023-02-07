#pragma once
#include "CoreMinimal.h"
#include "BoneReferenceEx.h"
#include "QuadrupedSpineRebase.generated.h"

USTRUCT(BlueprintType)
struct FQuadrupedSpineRebase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoneReferenceEx ParentBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBoneReferenceEx> RebaseBones;
    
    PHOENIX_API FQuadrupedSpineRebase();
};

