#pragma once
#include "CoreMinimal.h"
#include "BPGenericOnConversationFinishedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FBPGenericOnConversationFinished, FName, CharacterID, FName, ConversationID);

