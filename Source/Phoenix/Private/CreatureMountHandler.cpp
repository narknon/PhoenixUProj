#include "CreatureMountHandler.h"

class ACharacter;
class ACreature_Character;

bool ACreatureMountHandler::ToggleCreatureMountCapsule(ACreature_Character* InCreatureCharacter, const FName& InName, bool bInEnabled) const {
    return false;
}

void ACreatureMountHandler::SpawnAndMountCreature(ACharacter* InRiderCharacter, bool bInUseTransition, bool bInInFlight) {
}

void ACreatureMountHandler::PlayerPossessRider() {
}

void ACreatureMountHandler::PlayerPossessCreature() {
}



void ACreatureMountHandler::OnHoverDroneControlModeChanged(EHoverDroneControlMode::Type NewMode) {
}

void ACreatureMountHandler::MountExistingCreature(ACharacter* InRiderCharacter, ACreature_Character* InCreatureCharacter) {
}

bool ACreatureMountHandler::IsMountType(EMountTypes InType) const {
    return false;
}

void ACreatureMountHandler::DismountCreature(bool bInUseTransition) {
}

ACreatureMountHandler::ACreatureMountHandler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CreatureClass = NULL;
    this->CreatureSkeletalMeshPreload = NULL;
    this->PlayerMountAbility = NULL;
    this->RiderPostDismountAbility = NULL;
    this->ExistingCreatureInitialInteractionArchitectAsset = NULL;
    this->MountStreamingComponentClass = NULL;
    this->MountHeightLimitComponentClass = NULL;
    this->CreatureRiderComponentClass = NULL;
    this->CreatureMountComponentClass = NULL;
    this->MovementPredictionComponentClass = NULL;
    this->MountedAIControllerClass = NULL;
    this->CreatureMountVFXActorClass = NULL;
    this->MountedReactionsAsset = NULL;
    this->MountedInteractionsAsset = NULL;
    this->MountTransitionActorClass = NULL;
    this->MountTransitionActorAttachSocket = TEXT("Spine3");
    this->bAdjustSpawnForCollision = false;
    this->CreatureMountType = EMountTypes::Graphorn_Ground;
    this->CreaturePhysicAssetForRiderCloth = NULL;
    this->bDestroyHandlerAfterDismount = true;
    this->bDestroyCreatureAfterDismount = true;
    this->RiderCharacter = NULL;
    this->CreatureCharacter = NULL;
    this->RiderController = NULL;
    this->PreviousCreatureController = NULL;
    this->PreviousRiderController = NULL;
    this->MountTransitionActor = NULL;
    this->ChargeUnavailableMessageTimeout = 1.50f;
    this->ChargeOnCooldownMessageTimeout = 1.50f;
    this->FlightLandingDynamics = NULL;
    this->CreatureMountVFXActor = NULL;
    this->PreviousMountReactionsAsset = NULL;
    this->PreviousMountInteractionsAsset = NULL;
}

