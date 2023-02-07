#pragma once
#include "CoreMinimal.h"
#include "BonySkeletonTimerProfile.h"
#include "BonySkeletonTimerProfiles.generated.h"

USTRUCT(BlueprintType)
struct FBonySkeletonTimerProfiles {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBonySkeletonTimerProfile DefaultProfile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBonySkeletonTimerProfile> Profiles;
    
    PHOENIX_API FBonySkeletonTimerProfiles();
};

