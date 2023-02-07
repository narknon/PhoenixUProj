#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BlendTrackInfo.generated.h"

class UAblBlendSpaceParameterGetter;
class UAblBoneBlendWeightAsset;

USTRUCT(BlueprintType)
struct ABLECORE_API FBlendTrackInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimationTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAblBlendSpaceParameterGetter* BlendSpaceParameterGetter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAdditive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRotationOffsetMeshSpace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideMeshSpaceRotationBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMeshSpaceRotationBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAblBoneBlendWeightAsset* BoneWeightAsset;
    
    FBlendTrackInfo();
};

