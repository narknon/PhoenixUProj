#pragma once
#include "CoreMinimal.h"
#include "StoryNode_SceneRig.h"
#include "DialogueSequenceReference.h"
#include "StoryNode_DialogueSequence.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API UStoryNode_DialogueSequence : public UStoryNode_SceneRig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueSequenceReference DialogueSequence;
    
    UStoryNode_DialogueSequence();
};

