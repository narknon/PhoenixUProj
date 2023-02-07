#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConversationState.generated.h"

class AConversationActor;
class AStoryGraphActor;
class UStoryGraph_Conversation;

UCLASS(Blueprintable)
class PHOENIX_API UConversationState : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AStoryGraphActor* LegacyConversationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AConversationActor* OwnedConversationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStoryGraph_Conversation* CurrentConversation;
    
    UConversationState();
};

