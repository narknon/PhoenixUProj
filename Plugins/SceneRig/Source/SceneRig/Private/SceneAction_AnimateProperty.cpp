#include "SceneAction_AnimateProperty.h"

USceneAction_AnimateProperty::USceneAction_AnimateProperty() {
    this->BlendMode = ESceneAction_AnimateCurves_BlendMode::Replace;
    this->FillMode = ESceneAction_AnimateCurves_FillMode::Stretch;
    this->LoopCount = 1.00f;
    this->bKeepStateOnCompletion = false;
}

