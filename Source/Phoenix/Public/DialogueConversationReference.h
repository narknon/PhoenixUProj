#pragma once
#include "CoreMinimal.h"
#include "DialogueConversationReference.generated.h"

USTRUCT(BlueprintType)
struct FDialogueConversationReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EventID;
    
    PHOENIX_API FDialogueConversationReference();
};

