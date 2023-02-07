#pragma once
#include "CoreMinimal.h"
#include "BoneParticleTrackerEntry.h"
#include "BoneParticleTracker.generated.h"

USTRUCT(BlueprintType)
struct FBoneParticleTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBoneParticleTrackerEntry> Entries;
    
    PHOENIX_API FBoneParticleTracker();
};

