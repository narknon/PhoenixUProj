#include "PhoenixPathActor.h"

APhoenixPathActor::APhoenixPathActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PathDynamicMaterial = NULL;
    this->PathWidth = 0.00f;
    this->PathComponent = NULL;
}

