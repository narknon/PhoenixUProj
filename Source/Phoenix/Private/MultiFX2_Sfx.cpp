#include "MultiFX2_Sfx.h"

class UAkCallbackInfo;

void UMultiFX2_Sfx::OnAkPostEventFunc(EAkCallbackType CallbackType, UAkCallbackInfo* CallbackInfo) const {
}

UMultiFX2_Sfx::UMultiFX2_Sfx() {
    this->SFX = NULL;
    this->bPlayAtLocation = false;
    this->bIgnoreDeactivate = false;
    this->bStopWhenTargetDestroyed = true;
    this->bUseExistingAKComponent = false;
    this->bNoOcclusionOnPlayerTarget = true;
    this->bNoOcclusionOnPlayerInstigator = true;
    this->Occlusion = ESfxOcclusion::HulaHoop_8;
    this->bUseMotionListener = false;
    this->bUsePlayerOrientatedMotionListener = false;
}

