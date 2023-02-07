#include "SceneActionState_PlayBinkMedia.h"

void USceneActionState_PlayBinkMedia::OnMediaOpened(const FString& OpenedUrl) {
}

void USceneActionState_PlayBinkMedia::OnMediaFailedToOpen() {
}

USceneActionState_PlayBinkMedia::USceneActionState_PlayBinkMedia() {
    this->Widget = NULL;
    this->BinkMediaPlayer = NULL;
    this->bHasValidEnter = false;
}

