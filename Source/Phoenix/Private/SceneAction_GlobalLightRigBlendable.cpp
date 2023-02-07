#include "SceneAction_GlobalLightRigBlendable.h"

USceneAction_GlobalLightRigBlendable::USceneAction_GlobalLightRigBlendable() {
    this->GlobalLightingBlendable = NULL;
    this->FogZMode = EGlobalLightingSimpleFogZMode::OffsetOnly;
    this->FogZBase = NULL;
    this->Priority = 1000.00f;
    this->FeatherInTime = 0.00f;
    this->FeatherOutTime = 0.00f;
    this->bPreviewOnly = false;
}

