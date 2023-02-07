#pragma once
#include "CoreMinimal.h"
#include "RagdollBodyConstraintsConfig.generated.h"

USTRUCT(BlueprintType)
struct FRagdollBodyConstraintsConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FName> ConstrainedBodies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EaseInDuration;
    
    RAGDOLL_API FRagdollBodyConstraintsConfig();
};

