#include "FoliageRemoverContainer.h"

class UFoliageRemoverBoundsComponent;

void UFoliageRemoverContainer::UnregisterFoliageRemoverBoundsComponent(UFoliageRemoverBoundsComponent* Component) {
}

void UFoliageRemoverContainer::RegisterFoliageRemoverBoundsComponent(UFoliageRemoverBoundsComponent* Component) {
}

void UFoliageRemoverContainer::OnAnyLevelLoaded() {
}

UFoliageRemoverContainer::UFoliageRemoverContainer() {
    this->CachedWorld = NULL;
}

