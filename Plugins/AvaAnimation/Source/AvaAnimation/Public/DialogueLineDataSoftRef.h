#pragma once
#include "CoreMinimal.h"
#include "DialogueLineData.h"
#include "DialogueLineDataSoftRef.generated.h"

class UAnimSequence;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FDialogueLineDataSoftRef : public FDialogueLineData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimSequence> DialogueLineAnim;
    
    FDialogueLineDataSoftRef();
};

