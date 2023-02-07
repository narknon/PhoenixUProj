#pragma once
#include "CoreMinimal.h"
#include "DialogueLineRule_PickCamera_Event.h"
#include "DialogueLineRule_PickCamera_SpeakingActorEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_PickCamera_SpeakingActorEvent : public UDialogueLineRule_PickCamera_Event {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetFromDialogueLine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwitchCameraLengthThreshold;
    
    UDialogueLineRule_PickCamera_SpeakingActorEvent();
};

