#include "LocalStencilComponentBase.h"

class AActor;

bool ULocalStencilComponentBase::StartLocalStencilEffect(FLocalStencilEffect Effect) {
    return false;
}

void ULocalStencilComponentBase::LocalStencilEffectIsRunning(bool& bIsRunning, FLocalStencilEffect& RunningEffect) {
}

bool ULocalStencilComponentBase::EndLocalStencilEffect() {
    return false;
}

void ULocalStencilComponentBase::ActorStartLocalStencilEffect(AActor* Actor, FLocalStencilEffect Effect, bool& Success) {
}

void ULocalStencilComponentBase::ActorLocalStencilEffectIsRunning(AActor* Actor, bool& bIsRunning, FLocalStencilEffect& RunningEffect) {
}

void ULocalStencilComponentBase::ActorEndLocalStencilEffect(AActor* Actor, bool& Success) {
}

ULocalStencilComponentBase::ULocalStencilComponentBase() {
    this->MeshScaleFactor = 1.10f;
    this->TranslucentSortPriority = 0;
    this->bSetTranslucentSortPriority = false;
    this->Age = 0.00f;
    this->FadeInAge = 0.00f;
    this->FadeOutAge = 0.00f;
    this->MaterialMode = ELocalStencilMaterialMode::Default;
    this->bEffectActive = false;
    this->bStencilManagerLock = false;
    this->bFadingOut = false;
}

