#include "SpeedModeTracker.h"

void USpeedModeTracker::SetTargetSpeedMode(ETargetSpeedMode::Type InSpeedMode, ETargetSpeedPriority::Type InPriority, bool bBroadcastChange) {
}

void USpeedModeTracker::SetBaseTargetSpeedMode(ETargetSpeedMode::Type InSpeedMode) {
}

TEnumAsByte<ETargetSpeedMode::Type> USpeedModeTracker::GetTargetSpeedMode() {
    return ETargetSpeedMode::None;
}

TEnumAsByte<ETargetSpeedMode::Type> USpeedModeTracker::GetBaseTargetSpeedMode() {
    return ETargetSpeedMode::None;
}

void USpeedModeTracker::ClearTargetSpeedMode(ETargetSpeedPriority::Type InPriority, bool bBroadcastChange) {
}

USpeedModeTracker::USpeedModeTracker() {
}

