#pragma once
#include "CoreMinimal.h"
#include "ExplodingSkeletonBoneMesh.h"
#include "ExplodingSkeletonBoneMeshSetup.generated.h"

USTRUCT(BlueprintType)
struct FExplodingSkeletonBoneMeshSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExplodingSkeletonBoneMesh> Meshes;
    
    PHOENIX_API FExplodingSkeletonBoneMeshSetup();
};

