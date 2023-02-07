#include "TargetTypeBase.h"

void UTargetTypeBase::SetExpirationTime(float InExpirationTime) {
}

void UTargetTypeBase::SetComputedPriority(float InPriority) {
}

TEnumAsByte<ETargetType::Type> UTargetTypeBase::GetTargetType() {
    return ETargetType::None;
}

float UTargetTypeBase::GetExpirationTime() {
    return 0.0f;
}

float UTargetTypeBase::GetComputedPriority() {
    return 0.0f;
}

UTargetTypeBase::UTargetTypeBase() {
}

