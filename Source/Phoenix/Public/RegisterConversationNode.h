#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "RegisterConversationNodeOutputPinDelegate.h"
#include "RegisterConversationNode.generated.h"

class AActor;
class URegisterConversationNode;

UCLASS(Blueprintable)
class URegisterConversationNode : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRegisterConversationNodeOutputPin ConversationStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRegisterConversationNodeOutputPin ConversationFinished;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> interactionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName ConversationID;
    
public:
    URegisterConversationNode();
    UFUNCTION(BlueprintCallable)
    static URegisterConversationNode* RegisterConversation(AActor* NewInteractionActor, FName NewConversationID);
    
};

