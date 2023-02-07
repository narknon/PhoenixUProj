#include "InstallManagerProgressBar.h"

void UInstallManagerProgressBar::StartPendingLoad() {
}

float UInstallManagerProgressBar::GetInstallPercentage() {
    return 0.0f;
}

FString UInstallManagerProgressBar::GetInstallMessageText() {
    return TEXT("");
}

EInstallManagerState UInstallManagerProgressBar::GetInstallManagerState() {
    return EInstallManagerState::Idle;
}

UInstallManagerProgressBar::UInstallManagerProgressBar() : UUserWidget(FObjectInitializer::Get()) {
}

