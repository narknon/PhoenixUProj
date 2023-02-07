#include "StreamlineLibraryDLSSG.h"

void UStreamlineLibraryDLSSG::SetDLSSGMode(UStreamlineDLSSGMode DLSSGMode) {
}

void UStreamlineLibraryDLSSG::SetDLSSGFrames(int32 Frames) {
}

UStreamlineDLSSGSupport UStreamlineLibraryDLSSG::QueryDLSSGSupport() {
    return UStreamlineDLSSGSupport::Supported;
}

bool UStreamlineLibraryDLSSG::IsDLSSGSupported() {
    return false;
}

bool UStreamlineLibraryDLSSG::IsDLSSGModeSupported(UStreamlineDLSSGMode DLSSGMode) {
    return false;
}

TArray<UStreamlineDLSSGMode> UStreamlineLibraryDLSSG::GetSupportedDLSSGModes() {
    return TArray<UStreamlineDLSSGMode>();
}

void UStreamlineLibraryDLSSG::GetDLSSGSupportedFramesRange(int32& MinFrames, int32& MaxFrames) {
}

UStreamlineDLSSGMode UStreamlineLibraryDLSSG::GetDLSSGMode() {
    return UStreamlineDLSSGMode::Off;
}

void UStreamlineLibraryDLSSG::GetDLSSGMinimumDriverVersion(int32& MinDriverVersionMajor, int32& MinDriverVersionMinor) {
}

int32 UStreamlineLibraryDLSSG::GetDLSSGFrames() {
    return 0;
}

UStreamlineDLSSGMode UStreamlineLibraryDLSSG::GetDefaultDLSSGMode() {
    return UStreamlineDLSSGMode::Off;
}

UStreamlineLibraryDLSSG::UStreamlineLibraryDLSSG() {
}

