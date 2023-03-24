#include "TransfigurationSnappingTarget.h"

class UConjurationSnappingComponentBase;

void ATransfigurationSnappingTarget::ShowBeamAtLocalLocation_Implementation(const FVector& InLocationLocal) {
}

void ATransfigurationSnappingTarget::SetTargetObject_Implementation(UConjurationSnappingComponentBase* SnappingTarget) {
}

void ATransfigurationSnappingTarget::FadeOutAndDestroy_Implementation() {
}

void ATransfigurationSnappingTarget::ClearLitBeams_Implementation() {
}

ATransfigurationSnappingTarget::ATransfigurationSnappingTarget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TargetObject = NULL;
}

