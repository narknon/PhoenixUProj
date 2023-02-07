#include "DebugPanelComponent.h"

class UWorld;

void UDebugPanelComponent::ShowPanel(bool Show) {
}

bool UDebugPanelComponent::SetVisible(EDebugPanelControlID controlID, bool Visible) {
    return false;
}

bool UDebugPanelComponent::SetupShadow(EDebugPanelControlID controlID, FVector2D ShadowOffset, FLinearColor shadowColor) {
    return false;
}

bool UDebugPanelComponent::SetTextAndColor(EDebugPanelControlID controlID, const FString& Text, FLinearColor Color) {
    return false;
}

bool UDebugPanelComponent::SetText(EDebugPanelControlID controlID, const FString& Text) {
    return false;
}

bool UDebugPanelComponent::SetFont(EDebugPanelControlID controlID, FSlateFontInfo Font) {
    return false;
}

bool UDebugPanelComponent::SetColor(EDebugPanelControlID controlID, FLinearColor Color) {
    return false;
}

bool UDebugPanelComponent::PanelVisible() const {
    return false;
}

bool UDebugPanelComponent::IsMultilineText(EDebugPanelControlID controlID) {
    return false;
}

void UDebugPanelComponent::HidePanel() {
}

bool UDebugPanelComponent::EnableMultilineText(EDebugPanelControlID controlID, int32 lineLimit) {
    return false;
}

bool UDebugPanelComponent::DisableMultilineText(EDebugPanelControlID controlID) {
    return false;
}

bool UDebugPanelComponent::CreateUnique(UWorld* onlyForWorld) {
    return false;
}

bool UDebugPanelComponent::CreateShared(FName ID, UWorld* onlyForWorld) {
    return false;
}

bool UDebugPanelComponent::Created() const {
    return false;
}

bool UDebugPanelComponent::ClearText(EDebugPanelControlID controlID) {
    return false;
}

bool UDebugPanelComponent::ClearScrollingText() {
    return false;
}

bool UDebugPanelComponent::AppendTextLine(const FString& Text) {
    return false;
}

UDebugPanelComponent::UDebugPanelComponent() {
    this->Panel = NULL;
}

