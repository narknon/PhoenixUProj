#include "TransfigurationSpellToolBase.h"

class ATransfigurationPreviewActor;
class UTransformationSpellToolComponent;

void ATransfigurationSpellToolBase::TransformObject_FromMotion() {
}

void ATransfigurationSpellToolBase::SetTransformComponentRef(UTransformationSpellToolComponent* TC) {
}

void ATransfigurationSpellToolBase::ScaleUp() {
}

void ATransfigurationSpellToolBase::ScaleDown() {
}

void ATransfigurationSpellToolBase::RotateRight_FromMotion() {
}

void ATransfigurationSpellToolBase::RotateRight() {
}

void ATransfigurationSpellToolBase::RotateLeft_FromMotion() {
}

void ATransfigurationSpellToolBase::RotateLeft() {
}

bool ATransfigurationSpellToolBase::PrevTransformation() {
    return false;
}

void ATransfigurationSpellToolBase::PrevColor() {
}

void ATransfigurationSpellToolBase::PrepareToExit() {
}

void ATransfigurationSpellToolBase::PrepareToBack() {
}

bool ATransfigurationSpellToolBase::NextTransformation() {
    return false;
}

void ATransfigurationSpellToolBase::NextColor() {
}

bool ATransfigurationSpellToolBase::IsObjectStationary() const {
    return false;
}

bool ATransfigurationSpellToolBase::IsObjectScalable() const {
    return false;
}

bool ATransfigurationSpellToolBase::IsObjectRotatable() const {
    return false;
}

bool ATransfigurationSpellToolBase::HasTransformationOptions() const {
    return false;
}

bool ATransfigurationSpellToolBase::HasColorOptions() const {
    return false;
}

float ATransfigurationSpellToolBase::GetTransfigurationDuration() const {
    return 0.0f;
}

TArray<FTransfigurationResource> ATransfigurationSpellToolBase::GetRequiredResources() const {
    return TArray<FTransfigurationResource>();
}

ATransfigurationPreviewActor* ATransfigurationSpellToolBase::GetPreviewActor() const {
    return NULL;
}

ETransfigurationPlacementError ATransfigurationSpellToolBase::GetPlacementError() const {
    return ETransfigurationPlacementError::NoError;
}

float ATransfigurationSpellToolBase::GetHoldingDurationBeforeTransfigurationTimerStart() const {
    return 0.0f;
}

void ATransfigurationSpellToolBase::Exit() {
}

bool ATransfigurationSpellToolBase::DoesObjectSupportSnapping() const {
    return false;
}

bool ATransfigurationSpellToolBase::ConsumesSanctuaryContextResources() const {
    return false;
}

void ATransfigurationSpellToolBase::ConjurePreview_FromMotion() {
}

void ATransfigurationSpellToolBase::ConfirmTransfiguration_FromMotion() {
}

bool ATransfigurationSpellToolBase::ConfirmTransfiguration() {
    return false;
}

void ATransfigurationSpellToolBase::ColorObject_FromMotion() {
}

bool ATransfigurationSpellToolBase::CanPlaceItem() const {
    return false;
}

void ATransfigurationSpellToolBase::CancelPreview_FromMotion() {
}

void ATransfigurationSpellToolBase::Back() {
}

bool ATransfigurationSpellToolBase::AreResourceRequirementsMet() const {
    return false;
}

ATransfigurationSpellToolBase::ATransfigurationSpellToolBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TwirlDirection = 1.00f;
    this->HoldingDurationBeforeTransfigurationTimerStart = 0.25f;
    this->bWaitForCharacterAnimations = false;
}

