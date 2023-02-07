#pragma once
#include "CoreMinimal.h"
#include "DialogueConversationReference.h"
#include "MirroredFocusTrigger.h"
#include "FatLadyMirroredFocusTrigger.generated.h"

UCLASS(Blueprintable)
class AFatLadyMirroredFocusTrigger : public AMirroredFocusTrigger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference CalloutEventNight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference CalloutEventGryffindor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference CalloutEventNonGryffindor;
    
    AFatLadyMirroredFocusTrigger();
};

