#include "SpeedModeTracker.h"

void USpeedModeTracker::SetTargetSpeedMode(TEnumAsByte<ETargetSpeedMode::Type> InSpeedMode, TEnumAsByte<ETargetSpeedPriority::Type> InPriority, bool bBroadcastChange) {
}

void USpeedModeTracker::SetBaseTargetSpeedMode(TEnumAsByte<ETargetSpeedMode::Type> InSpeedMode) {
}

TEnumAsByte<ETargetSpeedMode::Type> USpeedModeTracker::GetTargetSpeedMode() {
    return ETargetSpeedMode::None;
}

TEnumAsByte<ETargetSpeedMode::Type> USpeedModeTracker::GetBaseTargetSpeedMode() {
    return ETargetSpeedMode::None;
}

void USpeedModeTracker::ClearTargetSpeedMode(TEnumAsByte<ETargetSpeedPriority::Type> InPriority, bool bBroadcastChange) {
}

USpeedModeTracker::USpeedModeTracker() {
}

