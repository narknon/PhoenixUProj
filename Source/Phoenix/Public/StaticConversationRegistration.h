#pragma once
#include "CoreMinimal.h"
#include "DialogueConversationReference.h"
#include "EConversationType.h"
#include "StaticConversationRegistration.generated.h"

class UStoryGraph_Conversation;

USTRUCT(BlueprintType)
struct FStaticConversationRegistration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EConversationType ConversationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference ArticyConversation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStoryGraph_Conversation* StoryGraph;
    
    PHOENIX_API FStaticConversationRegistration();
};

