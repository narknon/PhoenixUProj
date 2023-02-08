#pragma once
#include "CoreMinimal.h"
#include "AvaAudioGameplayStatics.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "DialogueConversationReference.h"
#include "AnimNotify_PlayAvaAudioDialogue.generated.h"



UCLASS(Blueprintable, CollapseCategories)
class UAnimNotify_PlayAvaAudioDialogue : public UAnimNotify {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference DialogueEventReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAvaAudioDialogueEvent* DialogueEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DialogueEventName;
    
public:
    UAnimNotify_PlayAvaAudioDialogue();
};

