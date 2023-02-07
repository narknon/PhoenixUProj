#pragma once
#include "CoreMinimal.h"
#include "ExplodingSkeletonGenericMeshSetup.h"
#include "ExplodingSkeletonGenericMeshSetupInstance.generated.h"

USTRUCT(BlueprintType)
struct FExplodingSkeletonGenericMeshSetupInstance : public FExplodingSkeletonGenericMeshSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Instances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WithFX;
    
    PHOENIX_API FExplodingSkeletonGenericMeshSetupInstance();
};

