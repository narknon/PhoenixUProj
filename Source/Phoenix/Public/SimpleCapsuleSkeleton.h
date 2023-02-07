#pragma once
#include "CoreMinimal.h"
#include "CapsuleBoundingSphere.h"
#include "SimpleCapsule.h"
#include "SimpleCapsuleSkeleton.generated.h"

USTRUCT(BlueprintType)
struct FSimpleCapsuleSkeleton {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FSimpleCapsule> Capsules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BoneKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCapsuleBoundingSphere Bounds;
    
    PHOENIX_API FSimpleCapsuleSkeleton();
};

