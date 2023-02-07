#include "SceneAction_MountCreature.h"

USceneAction_MountCreature::USceneAction_MountCreature() {
    this->Creature = NULL;
    this->MountHandlerClass = NULL;
    this->bForceMountOnEnter = true;
    this->bForceDismountOnExit = false;
    this->bUseDismountTransition = false;
    this->bStartFlying = false;
    this->bStopFlying = false;
    this->PathNode = NULL;
}

