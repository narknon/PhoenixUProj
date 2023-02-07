#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_RiderDialogue_DialogueReferenceList.h"
#include "DialogueConversationReference.h"
#include "AnimNotify_RiderDialogue.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UAnimNotify_RiderDialogue : public UAnimNotify {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogueConversationReference> DialogueEventReferences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FAnimNotify_RiderDialogue_DialogueReferenceList> PerCreatureDialogueEvents;
    
public:
    UAnimNotify_RiderDialogue();
};

