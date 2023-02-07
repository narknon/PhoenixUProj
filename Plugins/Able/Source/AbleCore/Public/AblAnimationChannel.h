#pragma once
#include "CoreMinimal.h"
#include "AblAnimationChannel.generated.h"

class UAblBoneBlendWeightAsset;

USTRUCT(BlueprintType)
struct ABLECORE_API FAblAnimationChannel {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAdditive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAblBoneBlendWeightAsset* BoneBlendWeightAsset;
    
public:
    FAblAnimationChannel();
};

