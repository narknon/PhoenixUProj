#include "IsmParent.h"

AIsmParent::AIsmParent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InstancedMesh = NULL;
    this->HierarchicalISM = false;
    this->DisableISM = false;
}

