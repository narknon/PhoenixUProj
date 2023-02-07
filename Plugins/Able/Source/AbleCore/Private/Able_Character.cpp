#include "Able_Character.h"
#include "RagdollControlComponent.h"
#include "AblAbilityComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class UAblAbility;
class UAblAbilityContext;
class UInteractionArchitectAsset;

bool AAble_Character::PlayAbilityByClass_Implementation(FName InAbilityChannelName, UClass* InAblAbilitClass, AActor* InInstigator) {
    return false;
}

bool AAble_Character::GetAbilityWithMultipleAssetsAndTags_Implementation(const FGameplayTagContainer& InSourceTagContainer, const TArray<UInteractionArchitectAsset*>& InArchitectAssets, const TArray<FGameplayTagContainer>& InArchitectTags, EInteractionProject Project, bool& bOutIsAdditive, TSubclassOf<UAblAbility>& OutAbilityClass) {
    return false;
}

bool AAble_Character::GetAbilityWithMultipleAssets_Implementation(const FGameplayTagContainer& InSourceTagContainer, const TArray<UInteractionArchitectAsset*>& InArchitectAssets, const FGameplayTagContainer& InArchitectTagContainer, EInteractionProject Project, bool& bOutIsAdditive, TSubclassOf<UAblAbility>& OutAbilityClass) {
    return false;
}

bool AAble_Character::GetAbilityFromInteractionArchitect_Implementation(const FGameplayTagContainer& InSourceTagContainer, UInteractionArchitectAsset* InArchitectAsset, const FGameplayTagContainer& InArchitectTagContainer, EInteractionProject Project, bool& bOutIsAdditive, TSubclassOf<UAblAbility>& OutAbilityClass) {
    return false;
}

bool AAble_Character::ExecuteAbilityOnChannelByClass_Implementation(FName ChannelName, UClass* InAblAbilitClass, AActor* InInstigator) {
    return false;
}

bool AAble_Character::ExecuteAbilityByClass_Implementation(UClass* InAblAbilitClass, AActor* InInstigator) {
    return false;
}

void AAble_Character::CancelAbilityByContext_Implementation(UAblAbilityContext* InAblAbilityContext) {
}

void AAble_Character::CancelAbilityByChannel_Implementation(FName InAbilityChannelName) {
}

AAble_Character::AAble_Character() {
    this->AblAbilityComponent = CreateDefaultSubobject<UAblAbilityComponent>(TEXT("AblAbilityComponent"));
    this->RagdollControlComponent = CreateDefaultSubobject<URagdollControlComponent>(TEXT("RagdollControlComponent"));
    this->PhysicalBodyManager = NULL;
}

