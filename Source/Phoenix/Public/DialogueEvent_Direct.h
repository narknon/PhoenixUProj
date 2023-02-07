#pragma once
#include "CoreMinimal.h"
#include "DialogueConversationReference.h"
#include "DialogueEventProvider.h"
#include "DialogueEvent_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UDialogueEvent_Direct : public UDialogueEventProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference DialogueEvent;
    
    UDialogueEvent_Direct();
};

