#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AudioDialogueLineData.h"
#include "SubtitleElement.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API USubtitleElement : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 AudioPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAudioDialogueLineData ElementAudioDialogueLineData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAudioEndedRecieved;
    
    USubtitleElement();
    UFUNCTION(BlueprintCallable)
    void InitAudioDialogueLineData(const FAudioDialogueLineData& AudioDialogueLineData);
    
};

