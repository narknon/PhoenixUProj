#pragma once
#include "CoreMinimal.h"
#include "DialogueConversationReference.h"
#include "AnimNotify_RiderDialogue_DialogueReferenceList.generated.h"

USTRUCT(BlueprintType)
struct FAnimNotify_RiderDialogue_DialogueReferenceList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogueConversationReference> DialogueEventReferences;
    
    PHOENIX_API FAnimNotify_RiderDialogue_DialogueReferenceList();
};

