#include "HUDElementGroup.h"

class UObject;

void UHUDElementGroup::ShowHUDElement(UObject* Provider) {
}

void UHUDElementGroup::HideHUDElement(UObject* Provider) {
}

bool UHUDElementGroup::GetShouldBeHidden() {
    return false;
}

UHUDElementGroup::UHUDElementGroup() : UUserWidget(FObjectInitializer::Get()) {
    this->MyGroup = UI_HUDGROUP_ACTIONRING;
    this->DesiredHiddenState = ESlateVisibility::Collapsed;
}

