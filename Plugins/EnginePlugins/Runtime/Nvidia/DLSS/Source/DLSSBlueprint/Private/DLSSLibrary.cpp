#include "DLSSLibrary.h"

void UDLSSLibrary::SetDLSSSharpness(float Sharpness) {
}

void UDLSSLibrary::SetDLSSMode(UDLSSMode DLSSMode) {
}

UDLSSSupport UDLSSLibrary::QueryDLSSSupport() {
    return UDLSSSupport::Supported;
}

bool UDLSSLibrary::IsDLSSSupported() {
    return false;
}

bool UDLSSLibrary::IsDLSSModeSupported(UDLSSMode DLSSMode) {
    return false;
}

bool UDLSSLibrary::IsDLAAEnabled() {
    return false;
}

TArray<UDLSSMode> UDLSSLibrary::GetSupportedDLSSModes() {
    return TArray<UDLSSMode>();
}

float UDLSSLibrary::GetDLSSSharpness() {
    return 0.0f;
}

void UDLSSLibrary::GetDLSSScreenPercentageRange(float& MinScreenPercentage, float& MaxScreenPercentage) {
}

void UDLSSLibrary::GetDLSSModeInformation(UDLSSMode DLSSMode, FVector2D ScreenResolution, bool& bIsSupported, float& OptimalScreenPercentage, bool& bIsFixedScreenPercentage, float& MinScreenPercentage, float& MaxScreenPercentage, float& OptimalSharpness) {
}

UDLSSMode UDLSSLibrary::GetDLSSMode() {
    return UDLSSMode::Off;
}

void UDLSSLibrary::GetDLSSMinimumDriverVersion(int32& MinDriverVersionMajor, int32& MinDriverVersionMinor) {
}

UDLSSMode UDLSSLibrary::GetDefaultDLSSMode() {
    return UDLSSMode::Off;
}

void UDLSSLibrary::EnableDLAA(bool bEnabled) {
}

UDLSSLibrary::UDLSSLibrary() {
}

