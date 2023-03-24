#include "Biped_Lightweight.h"
#include "FacialComponent.h"
#include "BipedStateComponent.h"

ABiped_Lightweight::ABiped_Lightweight(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FacialComponent = CreateDefaultSubobject<UFacialComponent>(TEXT("FacialComponent"));
    this->ObjectStateComponent = CreateDefaultSubobject<UBipedStateComponent>(TEXT("BipedStateComponent"));
}

