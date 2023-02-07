#pragma once
#include "CoreMinimal.h"
#include "TimeRig_StoryGraphNode.h"
#include "StoryNode_OutputEvent.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API UStoryNode_OutputEvent : public UTimeRig_StoryGraphNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RepresentsCompletion;
    
    UStoryNode_OutputEvent();
};

