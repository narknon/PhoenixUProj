#pragma once
#include "CoreMinimal.h"
#include "ForcedConversation.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FForcedConversation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Initiator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConversationID;
    
    PHOENIX_API FForcedConversation();
};

