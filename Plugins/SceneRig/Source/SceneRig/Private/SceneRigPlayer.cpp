#include "SceneRigPlayer.h"

class UObject;

bool USceneRigPlayer::UpdateTransformParameter(const FString& ParameterName, const FTransform& InValue) {
    return false;
}

bool USceneRigPlayer::UpdateStringParameter(const FString& ParameterName, const FString& InValue) {
    return false;
}

bool USceneRigPlayer::UpdateObjectParameter(const FString& ParameterName, UObject* Object) {
    return false;
}

bool USceneRigPlayer::UpdateIntParameter(const FString& ParameterName, int32 InValue) {
    return false;
}

bool USceneRigPlayer::UpdateFloatParameter(const FString& ParameterName, float InValue) {
    return false;
}

bool USceneRigPlayer::UpdateBoolParameter(const FString& ParameterName, bool InValue) {
    return false;
}

void USceneRigPlayer::ShowSkipUI(bool bShow) {
}

void USceneRigPlayer::ApplyParameterUpdatesImmediately() {
}

USceneRigPlayer::USceneRigPlayer() {
    this->OverridingFMV = NULL;
    this->OverridingBinkMedia = NULL;
    this->SkipWidget = NULL;
}

