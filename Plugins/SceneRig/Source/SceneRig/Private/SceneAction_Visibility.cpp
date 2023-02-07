#include "SceneAction_Visibility.h"

USceneAction_Visibility::USceneAction_Visibility() {
    this->Priority = EManagedVisibilityPriority::PassiveCinematic;
    this->ShouldBeHidden = true;
    this->IncludeChildActors = true;
}

