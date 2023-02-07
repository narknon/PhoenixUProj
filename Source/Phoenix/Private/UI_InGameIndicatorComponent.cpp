#include "UI_InGameIndicatorComponent.h"

void UUI_InGameIndicatorComponent::SetShowPointer(bool Show) {
}

bool UUI_InGameIndicatorComponent::GetShowPointer() {
    return false;
}

UUI_InGameIndicatorComponent::UUI_InGameIndicatorComponent() {
    this->PointerIndex = 0;
    this->ShowPointer = false;
}

