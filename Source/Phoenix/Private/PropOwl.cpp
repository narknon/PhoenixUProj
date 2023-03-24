#include "PropOwl.h"
#include "SkeletalMeshComponentBudgeted.h"
#include "AnimationComponent.h"
#include "Components/CapsuleComponent.h"

class AActor;
class ASpellTool;
class USpellToolRecord;

void APropOwl::StartReaction() {
}

void APropOwl::OnHitBySpell_Implementation(const ASpellTool* SpellTool, AActor* InInstigator, USpellToolRecord* SpellToolRecord, FName SpellType, const FHitResult& Hit, const FVector& ImpactDirection) {
}

void APropOwl::EndReaction() {
}

APropOwl::APropOwl(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponentBudgeted>(TEXT("SkeletalMeshComponent"));
    this->AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
    this->EnableSpellReaction = true;
    this->EnableImpactReaction = true;
    this->ImpactReactionRange = 100.00f;
    this->EnableLookAt = true;
    this->MaxLookAtDistance = 500.00f;
    this->MaxLookAtAngle = 75.00f;
    this->CanSleep = true;
    this->SleepingProbability = 0.25f;
    this->MinStanceSwitchTime = 45.00f;
    this->AnimInstance = NULL;
}

