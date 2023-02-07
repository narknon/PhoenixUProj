#include "FieldGuideButtonBase.h"

void UFieldGuideButtonBase::SetNewItemIndicatorVisibility() {
}



void UFieldGuideButtonBase::LockButton(bool ShouldLock) {
}

bool UFieldGuideButtonBase::GetLockedState() {
    return false;
}

UFieldGuideButtonBase::UFieldGuideButtonBase() {
    this->MenuTab = EPauseMenuPage::PAGE_INVENTORY;
}

