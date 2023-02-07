#pragma once
#include "CoreMinimal.h"
#include "StorySetupData.generated.h"

USTRUCT(BlueprintType)
struct FStorySetupData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocialAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ConnectionIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetConnectionsBitmask;
    
    PHOENIX_API FStorySetupData();
};

