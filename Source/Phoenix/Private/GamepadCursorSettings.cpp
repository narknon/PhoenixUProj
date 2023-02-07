#include "GamepadCursorSettings.h"

UGamepadCursorSettings::UGamepadCursorSettings() {
    this->MaxAnalogCursorSpeed = 960.00f;
    this->MaxAnalogCursorSpeedWhenHovered = 500.00f;
    this->AnalogCursorDragCoefficient = 100.00f;
    this->AnalogCursorDragCoefficientWhenHovered = 100.00f;
    this->MinAnalogCursorSpeed = 0.00f;
    this->AnalogCursorDeadZone = 0.15f;
    this->MinTimeToMaximumVelocity = 0.20f;
    this->AnalogCursorAccelerationMultiplier = 1.00f;
    this->AnalogCursorSize = 40.00f;
    this->bUseEngineAnalogCursor = false;
    this->bAnalogCursorNoAcceleration = true;
    this->TouchpadLerpSpeed = 0.60f;
    this->TouchpadScalarZone = 1.40f;
    this->TouchpadDeadZone = 20.00f;
    this->TouchpadDeadZoneWhenHovered = 35.00f;
}

