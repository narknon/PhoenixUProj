#include "Ladder.h"

float ALadder::GetMeshHeight_Implementation() const {
    return 0.0f;
}

float ALadder::GetLadderTopZ() const {
    return 0.0f;
}

int32 ALadder::GetLadderHeight_Implementation() const {
    return 0;
}

float ALadder::GetLadderBottomZ() const {
    return 0.0f;
}

void ALadder::EnablePlayerMountTop() {
}

void ALadder::EnablePlayerClimbing() {
}

void ALadder::DisablePlayerMountTop() {
}

void ALadder::DisablePlayerClimbing() {
}

bool ALadder::CanPlayerClimbLadder_Implementation() const {
    return false;
}

ALadder::ALadder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bPlayerClimbingEnabled = true;
    this->bPlayerMountTopEnabled = true;
}

