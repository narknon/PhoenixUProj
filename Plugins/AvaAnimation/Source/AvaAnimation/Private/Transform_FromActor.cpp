#include "Transform_FromActor.h"

void UTransform_FromActor::SetupFallback() const {
}

UTransform_FromActor::UTransform_FromActor() {
    this->Actor = NULL;
    this->ComponentToUse = EComponentToUse::FirstFoundMesh;
    this->FallbackTransform = NULL;
}

