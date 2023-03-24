#include "Portkey.h"

class ATargetPoint;
class UBTService_AvaAITree;

void APortkey::Transport() {
}

void APortkey::Touch() {
}

void APortkey::PlacePlayerOptimally() {
}

void APortkey::Interact_Implementation(UBTService_AvaAITree* AvaService) {
}





ATargetPoint* APortkey::GetTarget() {
    return NULL;
}

void APortkey::FindNonBlockingCameraLocation(FVector& Target1, FVector& Target2, FVector& CameraLocation, float CameraDistance, float CameraHeight) {
}

void APortkey::Drop() {
}

void APortkey::ActivateExitCamera() {
}

void APortkey::ActivateEnterCamera() {
}

APortkey::APortkey(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ParticleSystemComponent = NULL;
    this->ActorToTeleport = NULL;
    this->ExitEmitter = NULL;
    this->EntryEmitter = NULL;
    this->BeaconEmitter = NULL;
    this->UseBeaconEmitter = false;
    this->TargetA = NULL;
    this->TargetB = NULL;
    this->AtA = true;
    this->EjectForce = 0.00f;
    this->EntryCamDelay = 1.50f;
    this->ExitCamDelay = 3.00f;
    this->UseAdvancedExit = false;
    this->OnGround = false;
    this->OptimalDistance = 65.00f;
}

