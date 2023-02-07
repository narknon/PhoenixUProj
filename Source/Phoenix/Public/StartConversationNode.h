#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "StartConversationNodeOutputPinDelegate.h"
#include "StartConversationNode.generated.h"

class AActor;
class UStartConversationNode;

UCLASS(Blueprintable)
class UStartConversationNode : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartConversationNodeOutputPin ConversationStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartConversationNodeOutputPin ConversationFinished;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> interactionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName ConversationID;
    
public:
    UStartConversationNode();
    UFUNCTION(BlueprintCallable)
    static UStartConversationNode* StartConversation(AActor* NewInteractionActor, FName NewConversationID);
    
};

