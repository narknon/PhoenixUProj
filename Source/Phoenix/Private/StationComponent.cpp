#include "StationComponent.h"

class APawn;
class UMeshComponent;
class UObject;

bool UStationComponent::WillParticipateInSit() const {
    return false;
}

void UStationComponent::ValidateStation(TArray<FStationValidationError>& OutErrors) {
}

void UStationComponent::SetStationActive(bool Inactive) {
}

void UStationComponent::SetPropSelection(const FString& DesiredProp) {
}

bool UStationComponent::RequestAssetPreload() {
    return false;
}

bool UStationComponent::IsStationBreakable() {
    return false;
}

bool UStationComponent::IsStationActive() {
    return false;
}

bool UStationComponent::IsAChair() {
    return false;
}

bool UStationComponent::IsABookShelf() {
    return false;
}

bool UStationComponent::IsABed() {
    return false;
}

int32 UStationComponent::InitializeStationInteraction(UObject* InObject, EStationInteraction InDesiredInteraction, const FStationQueryData& InStationData, bool InDeferred, bool InWantCallback, float InTimeRequest, bool InJustGettingOptions) {
    return 0;
}

bool UStationComponent::GetStationUsers(TArray<UObject*>& outStationUsers) {
    return false;
}

FTransform UStationComponent::GetSocketTransform(FName InSocketName) {
    return FTransform{};
}

TEnumAsByte<PropTypeIDs> UStationComponent::GetPropType() {
    return PROP_TYPE_BED;
}

int32 UStationComponent::GetNumConnections() {
    return 0;
}

FString UStationComponent::GetMeshName() {
    return TEXT("");
}

UMeshComponent* UStationComponent::GetMeshComponent() {
    return NULL;
}

ECalloutActions UStationComponent::GetInteractionText() {
    return ECalloutActions::NOT_SET;
}

EStationInteraction UStationComponent::GetCurrentInteraction(int32 InInteractionID) {
    return EStationInteraction::STATION_INTERACTION_CURRENT_NONE;
}

FTransform UStationComponent::GetConnectionStartTransform(int32 InIndex) {
    return FTransform{};
}

int32 UStationComponent::GetClosestConnection(APawn* PlayerPawn) {
    return 0;
}

UStationComponent::UStationComponent() {
    this->IsDeprecated = false;
    this->m_Version = 2;
    this->m_IsActive = true;
    this->Type = TYPE_SPAWNED;
    this->SpawnedStationType = SPAWNED_STATION_TYPE_NONE;
    this->PropStaticMesh = NULL;
    this->PropSkeletalMesh = NULL;
    this->bDisallowSpellReactions = false;
    this->bGeneratePathing = true;
    this->AnimationPickingRange = 400.00f;
    this->StitchingActivateRadius = 200.00f;
    this->StoryTeller = NULL;
    this->SetupFlags = 0;
    this->EavesdropStation = false;
    this->AllowT4s = false;
    this->T4AnimSharingSetupMaleFemale[0] = NULL;
    this->T4AnimSharingSetupMaleFemale[1] = NULL;
    this->AllowStitching = true;
    this->bEnableIKFloorContact = false;
    this->PIP = PIP_ALWAYS;
    this->SetupHouseAndGender = 0;
    this->EnterExitAnimations[0] = ENTEREXITANIM_HUMAN_A;
    this->EnterExitAnimations[1] = ENTEREXITANIM_HUMAN_A;
    this->EnterExitAnimations[2] = ENTEREXITANIM_HUMAN_A;
    this->EnterExitAnimations[3] = ENTEREXITANIM_HUMAN_A;
    this->EnterExitAnimations[4] = ENTEREXITANIM_HUMAN_A;
    this->EnterExitAnimations[5] = ENTEREXITANIM_HUMAN_A;
    this->EnterExitAnimations[6] = ENTEREXITANIM_HUMAN_A;
    this->EnterExitAnimations[7] = ENTEREXITANIM_HUMAN_A;
    this->EnterExitAnimations[8] = ENTEREXITANIM_HUMAN_A;
    this->SnapConnectionsToTerrain = SCTG_UNKNOWN;
    this->CreateDynamicObstacle = true;
    this->InteractionText = ECalloutActions::Action_Join;
    this->IsVisible = true;
    this->VolumeType = EVolumeType::None;
    this->Volume = NULL;
    this->PatrolStationPriority = 0;
    this->PatrolStationTime = 10.00f;
    this->LimitPatrolToSingleUsePerCycle = false;
    this->bProhibitAutoLocationSetting = false;
    this->PlayerInVicinityVolume = NULL;
    this->MeshComponent = NULL;
    this->EnterDelay = 2.00f;
    this->EnterBlendIn = 2.00f;
    this->ExitDelay = 3.00f;
    this->ExitBlendOut = 2.00f;
    this->MaxAnimDriveStiffness = 0.90f;
    this->ForceParticipateInSit = false;
}

