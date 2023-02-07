#pragma once
#include "CoreMinimal.h"
#include "StoryGraphConditionBranchReference.generated.h"

USTRUCT(BlueprintType)
struct TIMERIG_API FStoryGraphConditionBranchReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BranchID;
    
    FStoryGraphConditionBranchReference();
};

