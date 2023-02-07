#pragma once
#include "CoreMinimal.h"
#include "StoryGraphConditionNodeReference.generated.h"

class UTimeRig_StoryGraphNode;

USTRUCT(BlueprintType)
struct TIMERIG_API FStoryGraphConditionNodeReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRig_StoryGraphNode* Node;
    
    FStoryGraphConditionNodeReference();
};

