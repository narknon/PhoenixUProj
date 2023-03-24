#include "TransformationStyleBase.h"

void ATransformationStyleBase::StartTransformation_Implementation() {
}

ATransformationStyleBase::ATransformationStyleBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OldPreviewActor = NULL;
    this->NewPreviewActor = NULL;
}

