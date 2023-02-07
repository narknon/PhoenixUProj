#include "SceneRig.h"

class UObject;
class USceneRigPlayer;

void USceneRig::StartPrecaching(UObject* WorldContextObject, const FSceneRigPrecacheCompleteBP& PrecacheComplete) const {
}

USceneRigPlayer* USceneRig::PlayWithDefaultParameters(UObject* WorldContextObject, UObject* PlayerParent, ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

USceneRigPlayer* USceneRig::Play(const FSceneRigParameters& Parameters, UObject* PlayerParent, ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

USceneRigPlayer* USceneRig::InitializePlayerWithDefaultParameters(UObject* WorldContext, UObject* PlayerParent, ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

USceneRigPlayer* USceneRig::InitializePlayer(const FSceneRigParameters& Parameters, UObject* PlayerParent, ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

USceneRigPlayer* USceneRig::FindPlayer(UObject* WorldContextObject) const {
    return NULL;
}

void USceneRig::CreateDefaultParameters(FSceneRigParameters& Parameters, UObject* WorldContextObject) const {
}

USceneRig::USceneRig() {
    this->BakeSequenceDebug = false;
    this->Interface = NULL;
    this->DefaultStage = NULL;
    this->PreviewStageDriver = true;
    this->DebugInEditor = false;
    this->StartDebuggingPaused = false;
    this->bShouldSimulatePhysics = true;
    this->bInstantlySkippable = false;
    this->PlayerSortOrder = 0.00f;
}

