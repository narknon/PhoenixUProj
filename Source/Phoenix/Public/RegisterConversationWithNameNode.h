#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "RegisterConversationWithNameNodeOutputPinDelegate.h"
#include "RegisterConversationWithNameNode.generated.h"

class URegisterConversationWithNameNode;

UCLASS(Blueprintable)
class URegisterConversationWithNameNode : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRegisterConversationWithNameNodeOutputPin ConversationStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRegisterConversationWithNameNodeOutputPin ConversationFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName CharacterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName ConversationID;
    
public:
    URegisterConversationWithNameNode();
    UFUNCTION(BlueprintCallable)
    static URegisterConversationWithNameNode* RegisterConversationWithName(FName NewCharacterID, FName NewConversationID);
    
};

