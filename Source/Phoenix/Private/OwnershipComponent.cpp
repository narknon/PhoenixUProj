#include "OwnershipComponent.h"

class AActor;
class UScheduledEntity;

bool UOwnershipComponent::IsTakingObjectStealing(const AActor* ObjectToTake, const AActor* WhoIsTaking) {
    return false;
}

bool UOwnershipComponent::IsEntityAnOwner(const AActor* Owned, const UScheduledEntity* ScheduledEntity) {
    return false;
}

bool UOwnershipComponent::HasOwnership(const AActor* Owned) {
    return false;
}

bool UOwnershipComponent::GetOwnership(const AActor* Owned, FString& o_OwnerName) {
    return false;
}

TEnumAsByte<SocialCapitalStatusIDs> UOwnershipComponent::GetMinimumPlayerStatusWithOwners(const AActor* OwnedObject) {
    return SOCIALCAPITAL_STATUS_STRANGER;
}

void UOwnershipComponent::CopyOwnership(const AActor* From, AActor* To) {
}

UOwnershipComponent::UOwnershipComponent() {
}

