#include "TransfigurationPreviewActor.h"
#include "Components/SceneComponent.h"

class AActor;
class ATransfigurationPreviewActor;
class ATransformationStyleBase;
class AVanishmentStyleBase;
class UMeshComponent;

bool ATransfigurationPreviewActor::UsesSurfacePlacement() const {
    return false;
}



void ATransfigurationPreviewActor::UnpauseAssociatedSkeletalMeshComponents() {
}

void ATransfigurationPreviewActor::TransformedFromOtherPreview_Implementation(ATransfigurationPreviewActor* InPreviousPreview) {
}

void ATransfigurationPreviewActor::SwitchToNewMesh() {
}




AVanishmentStyleBase* ATransfigurationPreviewActor::SpawnVanishmentStyle() {
    return NULL;
}

ATransformationStyleBase* ATransfigurationPreviewActor::SpawnTransformationStyle(ATransfigurationPreviewActor* InNewActor) {
    return NULL;
}

void ATransfigurationPreviewActor::SetSurfaceNormal(const bool bInSurfaceFound, const FVector& InSurfaceNormal) {
}

void ATransfigurationPreviewActor::SetSpawningIn(bool bIsSpawning) {
}

void ATransfigurationPreviewActor::SetCanPlace(const bool bInCanPlace) {
}

void ATransfigurationPreviewActor::SetAssociatedObjectActors(TArray<AActor*> InActorList) {
}

void ATransfigurationPreviewActor::ResetToOriginalScale_Implementation() {
}

void ATransfigurationPreviewActor::OnVanishStart_Implementation() {
}


void ATransfigurationPreviewActor::OnTransformStart_Implementation(ATransfigurationPreviewActor* InNewPreview) {
}



void ATransfigurationPreviewActor::OnFakeLoadDurationTimerElapsed() {
}


void ATransfigurationPreviewActor::ObjectDeselected_Implementation(AActor* InNewActor) {
}

void ATransfigurationPreviewActor::ObjectConfirmed_Implementation(const TArray<AActor*>& InNewActors) {
}

bool ATransfigurationPreviewActor::IsStationary() const {
    return false;
}

bool ATransfigurationPreviewActor::IsSpawningIn() const {
    return false;
}

bool ATransfigurationPreviewActor::IsReadyForPlacement_Implementation() const {
    return false;
}

bool ATransfigurationPreviewActor::IsPreviewInTransition_Implementation() const {
    return false;
}

bool ATransfigurationPreviewActor::IsPrefab() const {
    return false;
}

bool ATransfigurationPreviewActor::IsLocked() const {
    return false;
}

bool ATransfigurationPreviewActor::IsBeingRemoved() const {
    return false;
}

void ATransfigurationPreviewActor::HideActorAndChildren(AActor* InActor, bool bHide) {
}

void ATransfigurationPreviewActor::GetTransfigurationFxInfos(FVector& OutObjectCenter, FVector& OutObjectExtent) const {
}

FName ATransfigurationPreviewActor::GetTransfigurationClass() const {
    return NAME_None;
}

FTransform ATransfigurationPreviewActor::GetTargetTransform() const {
    return FTransform{};
}

void ATransfigurationPreviewActor::GetPreviewBounds(FVector& OutCenter, FVector& OutExtent) const {
}

FName ATransfigurationPreviewActor::GetObjectType() const {
    return NAME_None;
}

FName ATransfigurationPreviewActor::GetObjectCategory() const {
    return NAME_None;
}

bool ATransfigurationPreviewActor::GetIsPreviewMeshLoaded() const {
    return false;
}

FName ATransfigurationPreviewActor::GetColor() const {
    return NAME_None;
}

FTransform ATransfigurationPreviewActor::GetAttachmentTransform() const {
    return FTransform{};
}

FBox ATransfigurationPreviewActor::GetActorLocalPreviewBounds() const {
    return FBox{};
}




TArray<UMeshComponent*> ATransfigurationPreviewActor::DuplicateMeshComponents() {
    return TArray<UMeshComponent*>();
}



bool ATransfigurationPreviewActor::CanPlace() const {
    return false;
}


bool ATransfigurationPreviewActor::CanChangeColor() const {
    return false;
}

void ATransfigurationPreviewActor::CancelledIntoThinAir_Implementation() {
}






bool ATransfigurationPreviewActor::AreResourceRequirementsMet() const {
    return false;
}

ATransfigurationPreviewActor::ATransfigurationPreviewActor() {
    this->MovementStyle = NULL;
    this->TwirlDirection = 1.00f;
    this->Snapping = ETransfigurationSnapping::NoSnapping;
    this->bSurfaceFound = false;
    this->bCopyDecalComponents = true;
    this->bMaintainCollision = false;
    this->PreviewMeshRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PreviewMeshRoot"));
    this->bTestFixedLoadDuration = false;
    this->FixedLoadDuration = 0.00f;
}

