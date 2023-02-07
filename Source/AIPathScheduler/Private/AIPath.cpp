#include "AIPath.h"
#include "PathComponent.h"

void AAIPath::EnableApparate(bool InEnable) {
}

void AAIPath::Deactivate() {
}

void AAIPath::Activate() {
}

AAIPath::AAIPath() {
    this->BlendScale = 1.00f;
    this->UseAsEscapePath = true;
    this->BranchOnly = false;
    this->bStartActive = true;
    this->bApparateOnDeactivate = false;
    this->bAllowGroups = true;
    this->PathComponent = CreateDefaultSubobject<UPathComponent>(TEXT("Path"));
    this->bDataTransfered = false;
}

