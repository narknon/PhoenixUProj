#include "SceneAction_CharacterTeleport.h"

USceneAction_CharacterTeleport::USceneAction_CharacterTeleport() {
    this->WorldSpaceTransform = NULL;
    this->MinDistanceToTeleport = 0.00f;
}

