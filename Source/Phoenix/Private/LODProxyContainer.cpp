#include "LODProxyContainer.h"

ALODProxyContainer::ALODProxyContainer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BaseProxyMesh = NULL;
    this->AlphaMesh = NULL;
    this->LandscapeMeshProxyActor = NULL;
    this->DefaultMaterial = NULL;
    this->FallMaterial = NULL;
    this->WinterMaterial = NULL;
    this->LandscapeStaticMesh = NULL;
}

