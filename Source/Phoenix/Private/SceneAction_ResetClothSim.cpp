#include "SceneAction_ResetClothSim.h"

USceneAction_ResetClothSim::USceneAction_ResetClothSim() {
    this->bPiecesListIsInclusive = true;
    this->ClothTeleportMode = USceneAction_ResetClothSim_ClothingTeleportMode::TeleportAndReset;
}

