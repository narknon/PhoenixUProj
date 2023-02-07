#include "SceneActionState_CameraFixup.h"

USceneActionState_CameraFixup::USceneActionState_CameraFixup() {
    this->Layer = ECameraFixupLayer::Lowest;
    this->FirstFrameRefresh = false;
}

