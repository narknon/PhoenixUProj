#include "VirtualCursorFunctionLibrary.h"

class APlayerController;

void UVirtualCursorFunctionLibrary::SetCursorPostion(APlayerController* PC, float nx, float ny) {
}

void UVirtualCursorFunctionLibrary::SetCursorPositionDirect(APlayerController* PC, float nx, float ny) {
}

void UVirtualCursorFunctionLibrary::SetAllowMouseClickInput(bool Allow) {
}

bool UVirtualCursorFunctionLibrary::IsVirtualCursorEnabled() {
    return false;
}

bool UVirtualCursorFunctionLibrary::IsCursorOverInteractableWidget() {
    return false;
}

bool UVirtualCursorFunctionLibrary::GetIsUsingVirtualCursor() {
    return false;
}

bool UVirtualCursorFunctionLibrary::GetIsStickTouched() {
    return false;
}

FVector2D UVirtualCursorFunctionLibrary::GetCursorPostion() {
    return FVector2D{};
}

FVector2D UVirtualCursorFunctionLibrary::GetCursorPositionDirect() {
    return FVector2D{};
}

FVector2D UVirtualCursorFunctionLibrary::GetAnalogTriggerValues() {
    return FVector2D{};
}

FVector2D UVirtualCursorFunctionLibrary::GetAnalogRightValues() {
    return FVector2D{};
}

FVector2D UVirtualCursorFunctionLibrary::GetAnalogLeftValues() {
    return FVector2D{};
}

void UVirtualCursorFunctionLibrary::EnableVirtualCursor(APlayerController* PC) {
}

void UVirtualCursorFunctionLibrary::DisableVirtualCursor(APlayerController* PC) {
}

UVirtualCursorFunctionLibrary::UVirtualCursorFunctionLibrary() {
}

