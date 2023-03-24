#include "Foragable.h"

bool AForagable::ResetState_Implementation(EForageableState NextState) {
    return false;
}

FName AForagable::GetItemID_Implementation() const {
    return NAME_None;
}

int32 AForagable::GetItemCount_Implementation() const {
    return 0;
}

AForagable::AForagable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

