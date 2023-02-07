#pragma once
#include "CoreMinimal.h"
#include "TimeRig_StoryGraphNode.h"
#include "StoryNode_Custom.generated.h"

UCLASS(Abstract, Blueprintable)
class SCENERIG_API UStoryNode_Custom : public UTimeRig_StoryGraphNode {
    GENERATED_BODY()
public:
    UStoryNode_Custom();
};

