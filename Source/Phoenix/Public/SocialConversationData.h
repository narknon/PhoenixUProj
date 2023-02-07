#pragma once
#include "CoreMinimal.h"
#include "SocialConversationData.generated.h"

USTRUCT(BlueprintType)
struct FSocialConversationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConversationLine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConversationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DisplayStatus;
    
    PHOENIX_API FSocialConversationData();
};

