#include "CharacterBoneProjectionState.h"

FCharacterBoneProjectionState::FCharacterBoneProjectionState() {
    this->Age = 0.00f;
    this->bForwardValid = false;
    this->bMovementCohesionPoint = false;
    this->bProjectionDirty = false;
    this->bProjectionValid = false;
    this->bHidden = false;
    this->bAutoShow = false;
    this->bRenderedVisible = false;
    this->bRenderTransformDirty = false;
}

