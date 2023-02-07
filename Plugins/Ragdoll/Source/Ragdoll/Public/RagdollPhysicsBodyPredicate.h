#pragma once
#include "CoreMinimal.h"
#include "RagdollPhysicsBodyPredicate.generated.h"

class UPhysicsAsset;

USTRUCT(BlueprintType)
struct RAGDOLL_API FRagdollPhysicsBodyPredicate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicsAsset* WhenPhysicsAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> IncludedPhysicBodyBones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ExcludedPhysicBodyBones;
    
    FRagdollPhysicsBodyPredicate();
};

