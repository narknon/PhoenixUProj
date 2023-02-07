#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AudioDialogueLineData.h"
#include "Subtitles.generated.h"

class UVerticalBox;

UCLASS(Blueprintable, EditInlineNew)
class USubtitles : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* BP_Subtitle_Box;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* Subtitle_Box;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* Subtitle_Box_LowPriority;
    
    USubtitles();
    UFUNCTION(BlueprintCallable)
    void Setup();
    
    UFUNCTION(BlueprintCallable)
    void EvaluateSubtitleVerticalBox(UVerticalBox* Subtitle_VerticalBox);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BPUpdateStandaloneSubtitle(const FString& ResolvedSubtitle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BPRemoveSubtitleEvent(FAudioDialogueLineData SubtitleData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BPRemoveStandaloneSubtitle();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BPAddSubtitleEvent(FAudioDialogueLineData SubtitleData, const FString& ResolvedSubtitle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BPAddStandaloneSubtitle(const FString& ResolvedSubtitle);
    
};

