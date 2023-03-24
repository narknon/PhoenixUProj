#include "MunitionType_Base.h"

class AActor;
class UInteractionArchitectAsset;

void AMunitionType_Base::TargetDestroyed() {
}

void AMunitionType_Base::SetVelocityIncludeTarget(bool bInFlag) {
}

void AMunitionType_Base::SetTarget(AActor* i_pActor) {
}

void AMunitionType_Base::SetStartingVelocity(FVector InVelocity) {
}

void AMunitionType_Base::SetSourcePosition(FVector i_sourcePos) {
}

void AMunitionType_Base::SetRemainingLifeTime(float InRemaningTime) {
}

void AMunitionType_Base::SetRecomputeVelocity(bool bInFlag) {
}

void AMunitionType_Base::SetMunitionOwner(AActor* i_pActor) {
}

void AMunitionType_Base::SetMunitionImpactType(FName InMunitionImpactType) {
}

void AMunitionType_Base::SetMunitionDataAssets(const TArray<UInteractionArchitectAsset*>& InMunitionDataAssets) {
}

void AMunitionType_Base::SetMaxRange(float Range) {
}

void AMunitionType_Base::SetMaxDamage(float InMaxDamage) {
}

void AMunitionType_Base::SetLifeTime(float InMaxTime) {
}

void AMunitionType_Base::SetInstigator(AActor* i_pActor) {
}

void AMunitionType_Base::SetFromAimMode(bool bInFlag) {
}

void AMunitionType_Base::SetDestinationPosition(FVector i_destPos) {
}

void AMunitionType_Base::SetDamage(float InDamage) {
}

void AMunitionType_Base::ResetMunitionTagContainer() {
}

void AMunitionType_Base::ResetMunitionDataAssets() {
}

void AMunitionType_Base::RemoveMunitionTagContainer(const FGameplayTagContainer& InMunitionTagContainer) {
}

void AMunitionType_Base::RemoveMunitionTag(const FGameplayTag& InMunitionTag) {
}

void AMunitionType_Base::RemoveMunitionDataAsset(UInteractionArchitectAsset* InMunitionDataAsset) {
}

void AMunitionType_Base::MunitionIgnored() {
}

void AMunitionType_Base::MunitionFailed() {
}

void AMunitionType_Base::MunitionDOA() {
}

void AMunitionType_Base::MunitionDeflected() {
}

void AMunitionType_Base::MunitionBlocked() {
}

bool AMunitionType_Base::K2_WasMunitionDeflected() const {
    return false;
}

bool AMunitionType_Base::IsDeflectedMunition_K2() const {
    return false;
}

void AMunitionType_Base::IgnoreActor(AActor* InActor) {
}

bool AMunitionType_Base::GetVelocityIncludeTarget() const {
    return false;
}

AActor* AMunitionType_Base::GetTarget() const {
    return NULL;
}

FVector AMunitionType_Base::GetStartingVelocity() const {
    return FVector{};
}

FVector AMunitionType_Base::GetSourcePosition() const {
    return FVector{};
}

float AMunitionType_Base::GetRemainingLifeTime() const {
    return 0.0f;
}

bool AMunitionType_Base::GetRecomputeVelocity() const {
    return false;
}

FGameplayTagContainer AMunitionType_Base::GetMunitionTagContainer() const {
    return FGameplayTagContainer{};
}

AActor* AMunitionType_Base::GetMunitionOwner() const {
    return NULL;
}

FName AMunitionType_Base::GetMunitionImpactType() const {
    return NAME_None;
}

TArray<UInteractionArchitectAsset*> AMunitionType_Base::GetMunitionDataAssets() const {
    return TArray<UInteractionArchitectAsset*>();
}

float AMunitionType_Base::GetMaxRange() const {
    return 0.0f;
}

float AMunitionType_Base::GetMaxDamage() const {
    return 0.0f;
}

bool AMunitionType_Base::GetFromAimMode() const {
    return false;
}

FVector AMunitionType_Base::GetDestinationPosition() const {
    return FVector{};
}

float AMunitionType_Base::GetDamage() const {
    return 0.0f;
}

void AMunitionType_Base::Fire() {
}

FVector AMunitionType_Base::ComputeVelocity_NoGravity(FVector i_sourcePos, FVector i_destPos, FVector i_destVel, float i_speed, float& o_time) {
    return FVector{};
}

FVector AMunitionType_Base::ComputeVelocity(FVector i_sourcePos, FVector i_destPos, FVector i_destVel, float i_speed, float i_gravity, float& o_time, const bool assertOnError) {
    return FVector{};
}

void AMunitionType_Base::AddMunitionTagContainer(const FGameplayTagContainer& InMunitionTagContainer) {
}

void AMunitionType_Base::AddMunitionTag(const FGameplayTag& InMunitionTag) {
}

void AMunitionType_Base::AddMunitionDataAsset(UInteractionArchitectAsset* InMunitionDataAsset) {
}

AMunitionType_Base::AMunitionType_Base(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_damage = 0.00f;
    this->m_minLifeTime = 0.25f;
    this->m_maxLifeTime = 0.25f;
    this->bDOAOnParrySuccess = true;
}

