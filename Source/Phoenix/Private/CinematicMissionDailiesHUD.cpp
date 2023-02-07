#include "CinematicMissionDailiesHUD.h"

class USceneRig;
class USceneRigPlayer;

void UCinematicMissionDailiesHUD::UpdateStoryGraphName(const FString& NewSGName) {
}

void UCinematicMissionDailiesHUD::UpdateSceneRigName(const FString& NewSRName) {
}

void UCinematicMissionDailiesHUD::UpdateMissionID(const FString& NewMissionID) {
}




void UCinematicMissionDailiesHUD::SetSceneRig(USceneRig* InSceneRig) {
}





float UCinematicMissionDailiesHUD::GetHUDSRLength(USceneRigPlayer* SceneRigPlayer, USceneRig* InSceneRig, bool bInFrames) {
    return 0.0f;
}

float UCinematicMissionDailiesHUD::GetActiveSRFrame(USceneRigPlayer* SceneRigPlayer) {
    return 0.0f;
}

UCinematicMissionDailiesHUD::UCinematicMissionDailiesHUD() {
    this->bTotalFramesSet = false;
    this->bHasSceneRigBeenInitialized = false;
}

