#include "SceneAction_Transform.h"

USceneAction_Transform::USceneAction_Transform() {
    this->ParentTransform = NULL;
    this->bConstant = false;
    this->bHoldTransform = false;
    this->bApplyCharacterFixup = false;
    this->bForceTransform = false;
    this->bParentTransformIsStatic = false;
    this->ClothTeleportMode = ESceneAction_ClothingTeleportMode::None;
}

