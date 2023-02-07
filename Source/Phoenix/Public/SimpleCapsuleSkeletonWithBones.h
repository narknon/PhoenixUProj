#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimpleCapsuleSkeleton.h"
#include "SimpleCapsuleSkeletonWithBones.generated.h"

USTRUCT(BlueprintType)
struct FSimpleCapsuleSkeletonWithBones : public FSimpleCapsuleSkeleton {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FTransform> Bones;
    
    PHOENIX_API FSimpleCapsuleSkeletonWithBones();
};

