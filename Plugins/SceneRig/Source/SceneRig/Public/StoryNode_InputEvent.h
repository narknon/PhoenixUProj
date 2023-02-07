#pragma once
#include "CoreMinimal.h"
#include "TimeRig_StoryGraphNode.h"
#include "StoryNode_InputEvent.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API UStoryNode_InputEvent : public UTimeRig_StoryGraphNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEventCanTriggerMultipleTimes;
    
    UStoryNode_InputEvent();
};

