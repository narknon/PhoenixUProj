#include "SceneAction_HUDVisibility.h"

USceneAction_HUDVisibility::USceneAction_HUDVisibility() {
    this->ShouldBeHidden = true;
    this->ShowLetterboxUI = false;
    this->bAnimateOnEnter = true;
    this->bAnimateOnExit = true;
    this->Priority = EStandardManagedPriority::ActiveCinematic;
}

