#include "PerWorldAccessibilitySettings.h"

class AActor;
class UPrimitiveComponent;

void APerWorldAccessibilitySettings::RemovePrimitiveFromHighContrastGameplayBuckets(UPrimitiveComponent* PrimitiveComponent) {
}

void APerWorldAccessibilitySettings::RemoveActorFromHighContrastGameplayBuckets(AActor* Actor) {
}

void APerWorldAccessibilitySettings::RemoveActorFromHighContrastGameplayBucket(AActor* Actor, EHighContrastGameplayBucket Bucket) {
}

void APerWorldAccessibilitySettings::PrimitiveIsInHighContrastGameplayBucket(UPrimitiveComponent* PrimitiveComponent, EHighContrastGameplayBucket& Bucket, bool& bFound) {
}

void APerWorldAccessibilitySettings::AddPrimitiveToHighContrastGameplayBucket(UPrimitiveComponent* PrimitiveComponent, EHighContrastGameplayBucket Bucket) {
}

void APerWorldAccessibilitySettings::AddActorToHighContrastGameplayBucket(AActor* Actor, EHighContrastGameplayBucket Bucket) {
}

void APerWorldAccessibilitySettings::ActorIsInHighContrastGameplayBucket(AActor* Actor, EHighContrastGameplayBucket Bucket, bool& bFound) {
}

APerWorldAccessibilitySettings::APerWorldAccessibilitySettings() {
    this->TargetStencilValue = -1;
    this->SetBaseStencilValue = -1;
    this->LastSetTargetStencilValue = -1;
    this->LastFadeToBlackBlend = -1.00f;
    this->LastExtraValue = 0.00f;
    this->StateAlpha = 0.00f;
}

