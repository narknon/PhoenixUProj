#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "StartConversationWithNameNodeOutputPinDelegate.h"
#include "StartConversationWithNameNode.generated.h"

class UStartConversationWithNameNode;

UCLASS(Blueprintable)
class UStartConversationWithNameNode : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartConversationWithNameNodeOutputPin ConversationStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartConversationWithNameNodeOutputPin ConversationFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName CharacterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName ConversationID;
    
public:
    UStartConversationWithNameNode();
    UFUNCTION(BlueprintCallable)
    static UStartConversationWithNameNode* StartConversationWithName(FName NewCharacterID, FName NewConversationID);
    
};

