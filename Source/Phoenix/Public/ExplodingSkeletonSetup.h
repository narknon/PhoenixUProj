#pragma once
#include "CoreMinimal.h"
#include "ExplodingSkeletonBoneMeshSetup.h"
#include "ExplodingSkeletonGenericMeshSetup.h"
#include "ExplodingSkeletonSetupTimers.h"
#include "ExplodingSkeletonSetup.generated.h"

USTRUCT(BlueprintType)
struct FExplodingSkeletonSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExplodingSkeletonBoneMeshSetup> Attached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExplodingSkeletonSetupTimers AttachedBaseTimers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExplodingSkeletonGenericMeshSetup> Generic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExplodingSkeletonSetupTimers GenericBaseTimers;
    
    PHOENIX_API FExplodingSkeletonSetup();
};

