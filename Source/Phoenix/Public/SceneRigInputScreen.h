#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Types/SlateEnums.h"
#include "Layout/Margin.h"
#include "Blueprint/UserWidget.h"
#include "DialogueConversationReference.h"
#include "EFeedbackAnim.h"
#include "SceneRigInputScreen.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USceneRigInputScreen : public UUserWidget {
    GENERATED_BODY()
public:
    USceneRigInputScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TriggerVoLine(const FDialogueConversationReference SoundEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TriggerSoundEvent(const FString& SoundEvent);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTextKey(const FString& TextKey);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPromptImage(const FString& PromptImageName, FLinearColor PromptImageColor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPressAndHold(bool IsPressAndHold, float HoldDuration);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPositionAndPadding(EHorizontalAlignment HAlign, EVerticalAlignment VAlign, FMargin InPadding);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetModifierButtonCallout(const FString& ModButtonLegend, bool DisplayModifierFirst);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetFeedbackAnimation(EFeedbackAnim FeedbackAnim);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetButtonCallout(const FString& ButtonLegend);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPrimaryInputStateChanged(bool IsDown);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPressAndHoldStateChanged(bool IsDown);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModifierStateChanged(bool IsDown);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEndInteraction(bool Success);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCorrectInput();
    
    UFUNCTION(BlueprintCallable)
    void InitInputScreen(FMargin Margins, const FString& PromptImageName, const FString& ButtonLegend, const FString& ModifierButtonLegend, bool DisplayModifierFirst, const FString& TextKey, EFeedbackAnim FeedbackAnim, TEnumAsByte<EHorizontalAlignment> HAlign, TEnumAsByte<EVerticalAlignment> VAlign, FLinearColor PromptImageColor);
    
};

