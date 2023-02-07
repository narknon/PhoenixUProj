#include "PhoenixBPLibrary.h"

class AActor;
class UActorComponent;
class UForceResidentStreamableRenderAssetCollectionWrapper;
class UGearAppearanceItemDefinition;
class UObject;
class USceneComponent;
class USkeletalMeshComponent;
class UStationComponent;
class UWorld;

void UPhoenixBPLibrary::VerifyKey(const TArray<FString>& Keys) {
}

void UPhoenixBPLibrary::SetActorId(AActor* Actor, FName ActorId) {
}

TSoftObjectPtr<UObject> UPhoenixBPLibrary::MakeSoftObjectReferenceFromPath(const FSoftObjectPath& Path) {
    return NULL;
}

TSoftObjectPtr<UObject> UPhoenixBPLibrary::MakeSoftObjectReference(const FString& PathString) {
    return NULL;
}

UForceResidentStreamableRenderAssetCollectionWrapper* UPhoenixBPLibrary::LoadGearAppearanceItemDefinitionLODs(UWorld* World, TArray<UGearAppearanceItemDefinition*> GearAppearanceItemDefinitions, bool bIncludeTextures) {
    return NULL;
}

bool UPhoenixBPLibrary::IsRegexMatch(const FString& Pattern, const FString& Input) {
    return false;
}

bool UPhoenixBPLibrary::IsItemOwned(const FString& ProductID) {
    return false;
}

void UPhoenixBPLibrary::HermesExecuteOwnedStationComponent(const FString& Name, const UObject* Owner, const UObject* Caller, const UStationComponent* StationComponent) {
}

void UPhoenixBPLibrary::HermesExecuteOwnedSpellForce(const FString& Name, const UObject* Owner, const UObject* Caller, const FSpellForce& SpellForce) {
}

void UPhoenixBPLibrary::HermesExecuteOwnedReflectAttack(const FString& Name, const UObject* Owner, const UObject* Caller, const FDamageResult& DamageResult) {
}

void UPhoenixBPLibrary::HermesExecuteOwnedParryWindowEnd(const FString& Name, const UObject* Owner, const UObject* Caller, const FEnemy_ParryWindowEndData& ParryWindowEndData) {
}

void UPhoenixBPLibrary::HermesExecuteOwnedParryWindowBegin(const FString& Name, const UObject* Owner, const UObject* Caller, const FEnemy_ParryWindowBeginData& ParryWindowBeginData) {
}

void UPhoenixBPLibrary::HermesExecuteOwnedParryTimeToImpact(const FString& Name, const UObject* Owner, const UObject* Caller, const FEnemy_ParryTimeToImpactData& ParryTimeToImpactData) {
}

void UPhoenixBPLibrary::HermesExecuteOwnedParryEvent(const FString& Name, const UObject* Owner, const UObject* Caller, EEnemy_ParryButtonPressed ButtonPressed) {
}

void UPhoenixBPLibrary::HermesExecuteOwnedLock(const FString& Name, const UObject* Owner, const UObject* Caller, const FLockManagerLock& Lock) {
}

void UPhoenixBPLibrary::HermesExecuteOwnedInventoryResult(const FString& Name, const UObject* Owner, const UObject* Caller, const FInventoryResult& InventoryResult) {
}

void UPhoenixBPLibrary::HermesExecuteOwnedDamageResult(const FString& Name, const UObject* Owner, const UObject* Caller, const FDamageResult& DamageResult) {
}

void UPhoenixBPLibrary::HermesExecuteOwnedActorHitBySpell(const FString& Name, const UObject* Owner, const UObject* Caller, const FHitBySpellData& HitBySpell) {
}

void UPhoenixBPLibrary::HermesExecuteAllStationComponent(const FString& Name, const UObject* Caller, const UStationComponent* StationComponent) {
}

void UPhoenixBPLibrary::HermesExecuteAllSpellForce(const FString& Name, const UObject* Caller, const FSpellForce& SpellForce) {
}

void UPhoenixBPLibrary::HermesExecuteAllReflectAttack(const FString& Name, const UObject* Caller, const FDamageResult& DamageResult) {
}

void UPhoenixBPLibrary::HermesExecuteAllParryWindowEnd(const FString& Name, const UObject* Caller, const FEnemy_ParryWindowEndData& ParryWindowEndData) {
}

void UPhoenixBPLibrary::HermesExecuteAllParryWindowBegin(const FString& Name, const UObject* Caller, const FEnemy_ParryWindowBeginData& ParryWindowBeginData) {
}

void UPhoenixBPLibrary::HermesExecuteAllParryTimeToImpact(const FString& Name, const UObject* Caller, const FEnemy_ParryTimeToImpactData& ParryTimeToImpactData) {
}

void UPhoenixBPLibrary::HermesExecuteAllParryEvent(const FString& Name, const UObject* Caller, EEnemy_ParryButtonPressed ButtonPressed) {
}

void UPhoenixBPLibrary::HermesExecuteAllLock(const FString& Name, const UObject* Caller, const FLockManagerLock& Lock) {
}

void UPhoenixBPLibrary::HermesExecuteAllInventoryResult(const FString& Name, const UObject* Caller, const FInventoryResult& InventoryResult) {
}

void UPhoenixBPLibrary::HermesExecuteAllGameplayTags(const FString& Name, const UObject* Caller, const FGameplayTagContainerWrapper& Wrapper) {
}

void UPhoenixBPLibrary::HermesExecuteAllDamageResult(const FString& Name, const UObject* Caller, const FDamageResult& DamageResult) {
}

void UPhoenixBPLibrary::HermesExecuteAllActorHitBySpell(const FString& Name, const UObject* Caller, const FHitBySpellData& HitBySpell) {
}

void UPhoenixBPLibrary::HermesBindStationComponent(UPhoenixBPLibrary::FHermesStationComponentDelegate Delegate_StationComponent, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UPhoenixBPLibrary::HermesBindSpellForce(UPhoenixBPLibrary::FHermesSpellForceDelegate Delegate_MunitionImpactData, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UPhoenixBPLibrary::HermesBindReflectAttack(UPhoenixBPLibrary::FHermesReflectAttackDelegate Delegate_ReflectAttack, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UPhoenixBPLibrary::HermesBindParryWindowEnd(UPhoenixBPLibrary::FHermesParryWindowEndDelegate Delegate_ActorParryWindowEnd, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UPhoenixBPLibrary::HermesBindParryWindowBegin(UPhoenixBPLibrary::FHermesParryWindowBeginDelegate Delegate_ActorParryWindowBegin, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UPhoenixBPLibrary::HermesBindParryTimeToImpact(UPhoenixBPLibrary::FHermesParryTimeToImpactDelegate Delegate_ActorParryTimeToImpact, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UPhoenixBPLibrary::HermesBindParryEvent(UPhoenixBPLibrary::FHermesParryEventDelegate Delegate_ActorParryEvent, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UPhoenixBPLibrary::HermesBindLock(UPhoenixBPLibrary::FHermesLockDelegate Delegate_Lock, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UPhoenixBPLibrary::HermesBindInventoryResult(UPhoenixBPLibrary::FHermesInventoryResultDelegate Delegate_InventoryResult, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UPhoenixBPLibrary::HermesBindDamageResult(UPhoenixBPLibrary::FHermesDamageResultDelegate Delegate_DamageResult, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UPhoenixBPLibrary::HermesBindActorHitBySpell(UPhoenixBPLibrary::FHermesActorHitBySpellDelegate Delegate_ActorHitBySpell, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

FVector UPhoenixBPLibrary::GetRuntimeVectorCurveValue(const FRuntimeCurveVector& Curve, float Time) {
    return FVector{};
}

FLinearColor UPhoenixBPLibrary::GetRuntimeLinearColorCurveValue(const FRuntimeCurveLinearColor& Curve, float Time) {
    return FLinearColor{};
}

float UPhoenixBPLibrary::GetRuntimeFloatCurveValue(const FRuntimeFloatCurve& Curve, float Time) {
    return 0.0f;
}

TEnumAsByte<HouseIds> UPhoenixBPLibrary::GetObjectHouseID(const AActor* Actor) {
    return HOUSE_GRYFFINDOR;
}

TEnumAsByte<HouseIds> UPhoenixBPLibrary::GetHouseEnumFromHouseID(const FString& InHouseID) {
    return HOUSE_GRYFFINDOR;
}

FRotator UPhoenixBPLibrary::GetDisillusionmentEyeRotation(FName ParentSocket, USceneComponent* Mesh, const FVector& TargetLocation, const float MaxHorizontalAngle, const float MaxVerticalAngle) {
    return FRotator{};
}

FString UPhoenixBPLibrary::GetActorName(const AActor* Actor) {
    return TEXT("");
}

bool UPhoenixBPLibrary::GetActorId(const AActor* Actor, FName& OutActorId) {
    return false;
}

void UPhoenixBPLibrary::ForceUpdateTextureMips(const AActor* Actor) {
}

void UPhoenixBPLibrary::DestroyComponent(UActorComponent* Component, bool bPromoteChildren) {
}

void UPhoenixBPLibrary::CultureChanged() {
}

bool UPhoenixBPLibrary::ChangeOutfit(AActor* Actor, TArray<FName> GearIDs, TArray<USkeletalMeshComponent*>& OldMeshes, TArray<USkeletalMeshComponent*>& NewMeshes, bool bSkipChangingGear) {
    return false;
}

TSoftObjectPtr<UWorld> UPhoenixBPLibrary::CastToWorldSoftObjectReference(TSoftObjectPtr<UObject> ObjRef) {
    return NULL;
}

FText UPhoenixBPLibrary::AVATranslateSubtitle(const FString& Key, const FString& DebugLogText) {
    return FText::GetEmpty();
}

FText UPhoenixBPLibrary::AVATranslate(const FString& Key, const FString& DebugLogText) {
    return FText::GetEmpty();
}

bool UPhoenixBPLibrary::AvaIsRunningWithEditor() {
    return false;
}

bool UPhoenixBPLibrary::AvaIsRunningCommandlet() {
    return false;
}

UPhoenixBPLibrary::UPhoenixBPLibrary() {
}

