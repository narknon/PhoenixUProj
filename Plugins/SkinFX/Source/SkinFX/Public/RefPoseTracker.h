#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocatorTracker.h"
#include "RefPoseTracker.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FRefPoseTracker : public FLocatorTracker {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ReferenceTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BoneIndex;
    
public:
    FRefPoseTracker();
};

