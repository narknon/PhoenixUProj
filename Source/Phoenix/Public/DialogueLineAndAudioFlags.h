#pragma once
#include "CoreMinimal.h"
#include "AudioDialogueFlags.h"
#include "DialogueLineReference.h"
#include "DialogueLineAndAudioFlags.generated.h"

USTRUCT(BlueprintType)
struct FDialogueLineAndAudioFlags {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueLineReference DialogueLineReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAudioDialogueFlags AudioDialogueFlags;
    
    PHOENIX_API FDialogueLineAndAudioFlags();
};

