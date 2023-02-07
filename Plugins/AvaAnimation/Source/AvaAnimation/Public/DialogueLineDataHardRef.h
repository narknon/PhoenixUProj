#pragma once
#include "CoreMinimal.h"
#include "DialogueLineData.h"
#include "DialogueLineDataHardRef.generated.h"

class UAnimSequence;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FDialogueLineDataHardRef : public FDialogueLineData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* DialogueLineAnim;
    
    FDialogueLineDataHardRef();
};

