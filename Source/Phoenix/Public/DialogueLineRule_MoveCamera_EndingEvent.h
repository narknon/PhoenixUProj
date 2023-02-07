#pragma once
#include "CoreMinimal.h"
#include "DialogueLineRule_MoveCamera_Event.h"
#include "DialogueLineRule_MoveCamera_EndingEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_MoveCamera_EndingEvent : public UDialogueLineRule_MoveCamera_Event {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForChoicesAtEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetFromEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumPreviousCameraLength;
    
    UDialogueLineRule_MoveCamera_EndingEvent();
};

