#pragma once
#include "CoreMinimal.h"
#include "RagdollUprightRange.h"
#include "RagdollPoseState.generated.h"

USTRUCT(BlueprintType)
struct RAGDOLL_API FRagdollPoseState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRagdollUprightRange> PoseMatches;
    
    FRagdollPoseState();
};

