#include "SceneAction_SkinFX.h"

USceneAction_SkinFX::USceneAction_SkinFX() {
    this->SkinFX = NULL;
    this->MaterialLoadPriority = EMaterialPermuterLoadingPriority::Critical;
    this->bUseInitialParameters = false;
    this->bUseSceneRigParameters = false;
    this->bUseSwapRules = false;
    this->bUseNiagaraOverride = false;
    this->bUseEnvelopeOverride = false;
    this->bUseMeshStatesOverride = false;
}

