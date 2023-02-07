#include "TargetTracker.h"
#include "Templates/SubclassOf.h"

class AActor;
class UTargetTypeBase;

void UTargetTracker::RemoveTargetByPtr(ETargetID::Type InTargetID, UTargetTypeBase* InTargetToRemove) {
}

void UTargetTracker::RemoveTarget(ETargetID::Type InTargetID, bool bCheckForEmptyList) {
}

bool UTargetTracker::IsTargetListEmptyThisFrame() {
    return false;
}

TMap<TEnumAsByte<ETargetID::Type>, UTargetTypeBase*> UTargetTracker::GetTargets() {
    return TMap<TEnumAsByte<ETargetID::Type>, UTargetTypeBase*>();
}

FVector UTargetTracker::GetTargetLocation(TEnumAsByte<ETargetID::Type> InTargetID) {
    return FVector{};
}

UTargetTypeBase* UTargetTracker::GetTargetByID(TEnumAsByte<ETargetID::Type> InTargetType) const {
    return NULL;
}

AActor* UTargetTracker::GetTargetActor(TEnumAsByte<ETargetID::Type> InTargetID) {
    return NULL;
}

float UTargetTracker::GetComputedPriority(TEnumAsByte<ETargetID::Type> InTargetID) {
    return 0.0f;
}

TEnumAsByte<ETargetID::Type> UTargetTracker::GetBestTargetID() const {
    return ETargetID::None;
}

UTargetTypeBase* UTargetTracker::GetBestTarget() const {
    return NULL;
}

FVector UTargetTracker::ComputeTargetLocation(FVector ProjectFromLocation, float ProjectDistance) const {
    return FVector{};
}

FVector UTargetTracker::ComputeDirectionToTargetOfType(const FVector SourceLocation, TEnumAsByte<ETargetID::Type> InTargetID, bool bFlattenInXYPlane, bool bNormalize) {
    return FVector{};
}

FVector UTargetTracker::ComputeDirection(const FVector SourceLocation, bool bFlattenInXYPlane, bool bNormalize) {
    return FVector{};
}

FVector UTargetTracker::ComputeCameraDirection(AActor* InActor, bool bFlattenInXYPlane) {
    return FVector{};
}

bool UTargetTracker::AnyValidTargetsByType(TEnumAsByte<ETargetType::Type> InTargetType) const {
    return false;
}

bool UTargetTracker::AnyValidTargetsByID(TEnumAsByte<ETargetID::Type> InTargetID) const {
    return false;
}

bool UTargetTracker::AnyValidTargets() const {
    return false;
}

UTargetTypeBase* UTargetTracker::AddTarget_StaticWorldDirection(FVector InStaticWorldDirection, TEnumAsByte<ETargetID::Type> InTargetID) {
    return NULL;
}

UTargetTypeBase* UTargetTracker::AddTarget_Location(FVector InTargetLocation, TEnumAsByte<ETargetID::Type> InTargetID) {
    return NULL;
}

UTargetTypeBase* UTargetTracker::AddTarget_DesiredDirection(TEnumAsByte<ETargetID::Type> InTargetID) {
    return NULL;
}

UTargetTypeBase* UTargetTracker::AddTarget_Custom(TSubclassOf<UTargetTypeBase> TargetClass, TEnumAsByte<ETargetID::Type> InTargetID) {
    return NULL;
}

UTargetTypeBase* UTargetTracker::AddTarget_CameraDirection(TEnumAsByte<ETargetID::Type> InTargetID) {
    return NULL;
}

UTargetTypeBase* UTargetTracker::AddTarget_ActorWithOffset(AActor* InTargetActor, const FVector& InTargetOffset, TEnumAsByte<ETargetID::Type> InTargetID) {
    return NULL;
}

UTargetTypeBase* UTargetTracker::AddTarget_Actor(AActor* InTargetActor, TEnumAsByte<ETargetID::Type> InTargetID) {
    return NULL;
}

UTargetTracker::UTargetTracker() {
}

