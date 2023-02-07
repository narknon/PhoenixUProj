#include "CreatureInteractionTool.h"

void ACreatureInteractionTool::RequestInteractionEnd() {
}

void ACreatureInteractionTool::RemoveLookAtTarget() {
}

void ACreatureInteractionTool::RemoveFaceTarget() {
}





bool ACreatureInteractionTool::GetInteractionEndRequested() const {
    return false;
}

void ACreatureInteractionTool::EnableInteractionCamera() {
}

void ACreatureInteractionTool::DisableInteractionCamera() {
}

void ACreatureInteractionTool::AllowInteractionEnd() {
}

void ACreatureInteractionTool::AddLookAtTarget() {
}

void ACreatureInteractionTool::AddFaceTarget() {
}

ACreatureInteractionTool::ACreatureInteractionTool() {
    this->TargetCreature = NULL;
    this->Player = NULL;
    this->InteractingSpeedMode = ETargetSpeedMode::IsJogging;
    this->InteractRange = 1000.00f;
}

