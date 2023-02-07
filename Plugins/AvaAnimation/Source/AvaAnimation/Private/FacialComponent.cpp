#include "FacialComponent.h"

class AActor;
class UAnimSequence;

void UFacialComponent::StartSettingGazeState(const GazeStatesEnum InGazeState, const EManagedEyeStatePriority InPriority) {
}

void UFacialComponent::SetAmbientEyesDefaultValue(bool bValue) {
}

void UFacialComponent::SetAdditiveEyeTargetDefaultValue(bool bValue) {
}

void UFacialComponent::ReloadAnimDataTables() {
}

void UFacialComponent::OnHealthChanged(AActor* Actor, float Delta, bool bIndicateHUD) {
}

void UFacialComponent::OnCharacterLoadComplete(AActor* Actor) {
}

bool UFacialComponent::IsPlayingDialogueLine() {
    return false;
}

bool UFacialComponent::IsLoadingDialogueLineAnimDataTables() {
    return false;
}

UAnimSequence* UFacialComponent::GetFacialEmotionAnim(FName Emotion, FGameplayTagContainer AnimTags) {
    return NULL;
}

UAnimSequence* UFacialComponent::GetFacialAnimByTags(FGameplayTagContainer AnimTags) {
    return NULL;
}

TSoftObjectPtr<UAnimSequence> UFacialComponent::GetDialogueLineAnim(FName DialogueLine) {
    return NULL;
}

EFacialEmotion UFacialComponent::GetActiveFacialEmotion() {
    return EFacialEmotion::NONE;
}

void UFacialComponent::FinishSettingGazeState(const EManagedEyeStatePriority InPriority) {
}

bool UFacialComponent::EditorPlayDialogueLine(FName DialogueLine, FName OverrideDialogueLineEmotion) {
    return false;
}

bool UFacialComponent::EditorLoadLanguage(const FString& Lang) {
    return false;
}

TArray<FName> UFacialComponent::EditorGetDialogueLineIds() {
    return TArray<FName>();
}

bool UFacialComponent::EditorCancelPlayingCurrentDialogueLine() {
    return false;
}

void UFacialComponent::DoubleBlinkNow() {
}

void UFacialComponent::BlinkNow() {
}

UFacialComponent::UFacialComponent() {
    this->DialogueAnimRequest = NULL;
    this->FacialEmotionAnimRequest = NULL;
    this->FacialAnimationAnimRequest = NULL;
    this->AmbientEyesAnimRequest = NULL;
    this->CurrentDialogueLineAnim = NULL;
}

