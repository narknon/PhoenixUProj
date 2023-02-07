#pragma once
#include "CoreMinimal.h"
#include "AblBoneBlendWeightAsset.h"
#include "AblSimpleBlendWeightAsset.generated.h"

UCLASS(Blueprintable)
class ABLECORE_API UAblSimpleBlendWeightAsset : public UAblBoneBlendWeightAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> BlendWeightMap;
    
    UAblSimpleBlendWeightAsset();
};

