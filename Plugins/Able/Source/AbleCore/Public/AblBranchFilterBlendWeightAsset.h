#pragma once
#include "CoreMinimal.h"
#include "AblBoneBlendWeightAsset.h"
#include "MyInputBlendPose.h"
#include "AblBranchFilterBlendWeightAsset.generated.h"

UCLASS(Blueprintable)
class ABLECORE_API UAblBranchFilterBlendWeightAsset : public UAblBoneBlendWeightAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMyInputBlendPose> LayerSetup;
    
    UAblBranchFilterBlendWeightAsset();
};

