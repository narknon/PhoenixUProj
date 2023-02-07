#include "Able_AnimInstance.h"

void UAble_AnimInstance::Set_LastDesiredWorldDirection_Implementation(FVector InWorldDirection) {
}

void UAble_AnimInstance::Set_FixedYaw(const float InFixedYawRemaining, const float InFixedYawOffset, const float SampleTime) {
}

void UAble_AnimInstance::Set_DesiredWorldSpeed_Implementation(float InSpeed) {
}

void UAble_AnimInstance::Set_DesiredWorldDirection_Implementation(FVector InWorldDirection) {
}

void UAble_AnimInstance::Get_LastDesiredWorldDirection_Implementation(FVector& OutWorldDirection) {
}

void UAble_AnimInstance::Get_FixedYawSampleTime(float& OutFixedYawSampleTime) {
}

void UAble_AnimInstance::Get_FixedYawRemaining(float& OutFixedYawRemaining) {
}

void UAble_AnimInstance::Get_FixedYawOffset(float& OutFixedYawOffset) {
}

void UAble_AnimInstance::Get_DesiredWorldSpeed_Implementation(float& OutSpeed) {
}

void UAble_AnimInstance::Get_DesiredWorldDirection_Implementation(FVector& OutWorldDirection) {
}

UAble_AnimInstance::UAble_AnimInstance() {
    this->InIdle = false;
    this->DesiredWorldSpeed = 0.00f;
    this->RateMultiplierOverride = 1.00f;
    this->FixedYawRemaining = 0.00f;
    this->FixedYawOffset = 0.00f;
    this->FixedYawSampleTime = -1.00f;
    this->AbleAbilityComponent = NULL;
}

