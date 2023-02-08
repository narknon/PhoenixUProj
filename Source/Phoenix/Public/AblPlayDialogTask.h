#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AnimNotify_PlayAvaAudioDialogue.h"
#include "AudioDialogueFlags.h"
#include "DialogueConversationReference.h"
#include "AblPlayDialogTask.generated.h"



UCLASS(Blueprintable, EditInlineNew)
class UAblPlayDialogTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference DialogEventReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAvaAudioDialogueEvent* DialogEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAudioDialogueFlags AudioDialogueFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopWhenAttachedToDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopDialogueOnEndTask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FName> AllowedSubtypeIDs;
    
public:
    UAblPlayDialogTask();
};

