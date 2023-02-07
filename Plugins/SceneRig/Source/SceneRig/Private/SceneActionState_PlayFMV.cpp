#include "SceneActionState_PlayFMV.h"

void USceneActionState_PlayFMV::OnMediaOpened(const FString& OpenedUrl) {
}

USceneActionState_PlayFMV::USceneActionState_PlayFMV() {
    this->Widget = NULL;
    this->MediaPlayer = NULL;
}

