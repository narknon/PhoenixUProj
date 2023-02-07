#include "CameraStack.h"
#include "Templates/SubclassOf.h"

class ACameraStackActor;
class UCameraStackBehavior;
class UCameraStackBehaviorCore;
class UCameraStackBehaviorMultiBehaviorBlend;
class UObject;

bool UCameraStack::UnpauseBehavior(UCameraStackBehavior* InBehavior) {
    return false;
}

bool UCameraStack::ResetBehaviors(UCameraStackBehaviorCore* InBehavior) {
    return false;
}

bool UCameraStack::ReplaceCoreBehavior(UCameraStackBehaviorCore* InBehavior, float InBlendOutDuration, float InBlendInDuration) {
    return false;
}

bool UCameraStack::ReplaceBehavior(UCameraStackBehavior* InBehavior, const UCameraStackBehavior* InPredecessorBehavior, float InBlendOutDuration, float InBlendInDuration) {
    return false;
}

bool UCameraStack::RemoveBehavior(UCameraStackBehavior* InBehavior, float InBlendOutDuration) {
    return false;
}

bool UCameraStack::PauseBehavior(UCameraStackBehavior* InBehavior) {
    return false;
}

bool UCameraStack::InsertBeforeBehavior(UCameraStackBehavior* InBehavior, const UCameraStackBehavior* InBeforeBehavior, float InBlendInDuration) {
    return false;
}

bool UCameraStack::InsertAfterBehavior(UCameraStackBehavior* InBehavior, const UCameraStackBehavior* InAfterBehavior, float InBlendInDuration) {
    return false;
}

UCameraStackBehavior* UCameraStack::GetTopmostBehavior() const {
    return NULL;
}

bool UCameraStack::GetRotationLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax) {
    return false;
}

ACameraStackActor* UCameraStack::GetOwner() const {
    return NULL;
}

bool UCameraStack::GetFocusDistanceLimits(float& OutMin, float& OutMax) {
    return false;
}

bool UCameraStack::GetFieldOfViewLimits(float& OutMin, float& OutMax) {
    return false;
}

UCameraStackBehaviorCore* UCameraStack::GetCoreBehavior() const {
    return NULL;
}

bool UCameraStack::GetCameraSpaceTranslationLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax) {
    return false;
}

bool UCameraStack::GetCameraSpaceRotationLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax) {
    return false;
}

UCameraStackBehavior* UCameraStack::GetBehaviourWithType(TSubclassOf<UCameraStackBehavior> InType, ECameraStackBehaviorSorting InSorting, int32 FilterFlags) const {
    return NULL;
}

UCameraStackBehavior* UCameraStack::GetBehaviorWithTypes(const TArray<TSubclassOf<UCameraStackBehavior>>& InTypes, ECameraStackBehaviorSorting InSorting, int32 FilterFlags) const {
    return NULL;
}

TArray<UCameraStackBehavior*> UCameraStack::GetBehaviorsWithTypes(const TArray<TSubclassOf<UCameraStackBehavior>>& InTypes, ECameraStackBehaviorSorting InSorting, int32 FilterFlags) const {
    return TArray<UCameraStackBehavior*>();
}

TArray<UCameraStackBehavior*> UCameraStack::GetBehaviorsWithType(TSubclassOf<UCameraStackBehavior> InType, ECameraStackBehaviorSorting InSorting, int32 FilterFlags) const {
    return TArray<UCameraStackBehavior*>();
}

bool UCameraStack::GetArmOriginLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax) {
    return false;
}

bool UCameraStack::GetArmLengthLimits(float& OutMin, float& OutMax) {
    return false;
}

bool UCameraStack::GetApertureLimits(float& OutMin, float& OutMax) {
    return false;
}

bool UCameraStack::EnableBehavior(UCameraStackBehavior* InBehavior, float InBlendInDuration) {
    return false;
}

bool UCameraStack::DisableBehavior(UCameraStackBehavior* InBehavior, float InBlendOutDuration) {
    return false;
}

UCameraStackBehavior* UCameraStack::CreateNonCoreBehavior(TSubclassOf<UCameraStackBehavior> BehaviorClass, UObject* Template) {
    return NULL;
}

UCameraStackBehaviorCore* UCameraStack::CreateCoreBehavior(TSubclassOf<UCameraStackBehaviorCore> BehaviorClass, UObject* Template) {
    return NULL;
}

bool UCameraStack::ContainsBehaviorWithType(const TSubclassOf<UCameraStackBehavior>& InType, int32 FilterFlags) const {
    return false;
}

UCameraStackBehaviorMultiBehaviorBlend* UCameraStack::AddStackBehaviors(const FCameraStackData& InStackData, float InBlendInDuration) {
    return NULL;
}

bool UCameraStack::AddBehavior(UCameraStackBehavior* InBehavior, float InBlendInDuration, bool bInSkipFlags) {
    return false;
}

UCameraStack::UCameraStack() {
}

