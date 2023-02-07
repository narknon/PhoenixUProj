#include "MapRegionBox.h"
#include "Components/BoxComponent.h"

AMapRegionBox::AMapRegionBox() {
    this->WorldID = TEXT("Hogwarts");
    this->TypeID = TEXT("MapRegion");
    this->Region = CreateDefaultSubobject<UBoxComponent>(TEXT("Region"));
}

