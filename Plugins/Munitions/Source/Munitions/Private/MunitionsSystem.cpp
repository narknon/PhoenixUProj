#include "MunitionsSystem.h"
#include "Templates/SubclassOf.h"

class AActor;
class AMunitionType_Base;
class APawn;
class UObject;

AMunitionType_Base* UMunitionsSystem::SpawnMunition(TSubclassOf<AMunitionType_Base> MunitionClass, AActor* MunitionOwner, APawn* Instigator, const FVector& SourcePos) {
    return NULL;
}

void UMunitionsSystem::SetMunitionImpactFailed() {
}

void UMunitionsSystem::SendSpellMadeContact(UObject* Owner, UObject* Caller, const FMunitionImpactData& miData) {
}

void UMunitionsSystem::SendMunitionImpactDamage(UObject* Owner, UObject* Caller, const FMunitionImpactData& miData) {
}

bool UMunitionsSystem::SendMunitionImpactCombined(UObject* Owner, UObject* Caller, const FMunitionImpactData& miData) {
    return false;
}

void UMunitionsSystem::SendMunitionImpact(UObject* Owner, UObject* Caller, const FMunitionImpactData& miData) {
}

void UMunitionsSystem::MunitionToInstigator(UObject* Owner, UObject* Caller, const FMunitionToInstigatorData& mtoIData) {
}

void UMunitionsSystem::DestroySpawnedMunition(AMunitionType_Base* Munition) {
}

UMunitionsSystem::UMunitionsSystem() {
}

