#pragma once
#include "CoreMinimal.h"
#include "BPGenericOnConversationStartedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FBPGenericOnConversationStarted, FName, CharacterID, FName, ConversationID);

