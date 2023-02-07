#pragma once
#include "CoreMinimal.h"
#include "BoneSwarmGenerationParameters.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FBoneSwarmGenerationParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Members;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* MemberMesh;
    
    PHOENIX_API FBoneSwarmGenerationParameters();
};

