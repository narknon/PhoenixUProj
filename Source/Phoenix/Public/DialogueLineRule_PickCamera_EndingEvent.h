#pragma once
#include "CoreMinimal.h"
#include "DialogueLineRule_PickCamera_Event.h"
#include "DialogueLineRule_PickCamera_EndingEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_PickCamera_EndingEvent : public UDialogueLineRule_PickCamera_Event {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForChoicesAtEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForBeforeEmbeddedSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetFromEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumOffsetFromEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumPreviousCameraLength;
    
    UDialogueLineRule_PickCamera_EndingEvent();
};

