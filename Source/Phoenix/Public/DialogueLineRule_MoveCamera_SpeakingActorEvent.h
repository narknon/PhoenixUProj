#pragma once
#include "CoreMinimal.h"
#include "DialogueLineRule_MoveCamera_Event.h"
#include "DialogueLineRule_MoveCamera_SpeakingActorEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_MoveCamera_SpeakingActorEvent : public UDialogueLineRule_MoveCamera_Event {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetFromDialogueLine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwitchCameraLengthThreshold;
    
    UDialogueLineRule_MoveCamera_SpeakingActorEvent();
};

