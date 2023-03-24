#include "AnimationArchitect_Character.h"
#include "AnimationArchitectComponent.h"
#include "SkeletalMeshComponentBudgeted.h"

class UObject;

UAnimationArchitectComponent* AAnimationArchitect_Character::GetAnimationArchitectComponent_Implementation() const {
    return NULL;
}

bool AAnimationArchitect_Character::FindArchitectAssets_Implementation(const FGameplayTagContainer& InAnimTagContainer, TArray<UObject*>& Assets) {
    return false;
}

void AAnimationArchitect_Character::FindArchitectAssetFromMonolythicAsset_Implementation(const FGameplayTagContainer& InAssetTypeTagContainer, const FGameplayTagContainer& InTagContainer, UObject*& OutAsset, bool bForceFirstOnly) {
}

void AAnimationArchitect_Character::FindArchitectAsset_Implementation(const FGameplayTagContainer& InAnimTagContainer, UObject*& OutAsset, bool bForceFirstOnly) {
}

void AAnimationArchitect_Character::AddInteractionArchitectGameplayTag_Implementation(const FGameplayTag& InGamepayTag) {
}

void AAnimationArchitect_Character::AddAnimationArchitectGameplayTag_Implementation(const FGameplayTag& InGameplayTag) {
}

AAnimationArchitect_Character::AAnimationArchitect_Character(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<USkeletalMeshComponentBudgeted>(TEXT("CharacterMesh0"))) {
    this->AnimationArchitectComponent = CreateDefaultSubobject<UAnimationArchitectComponent>(TEXT("AnimationArchitectComponent"));
}

