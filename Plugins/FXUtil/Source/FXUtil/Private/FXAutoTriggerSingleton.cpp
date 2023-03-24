#include "FXAutoTriggerSingleton.h"

class AActor;
class UFXAutoTriggerDefinitionAsset;
class UObject;

void AFXAutoTriggerSingleton::SetWorldCustomCondition(UObject* WorldContextObject, FName WorldConditionName, bool bEnabled) {
}

void AFXAutoTriggerSingleton::SetActorCustomCondition(AActor* Actor, FName ActorConditionName, bool bEnabled) {
}

void AFXAutoTriggerSingleton::RemoveManualActors(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, TArray<AActor*> Actors, bool& bResult) {
}

void AFXAutoTriggerSingleton::RemoveManualActor(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool& bResult) {
}

void AFXAutoTriggerSingleton::RemoveCustomBucketActor(AActor* Actor, FName CustomBucket) {
}

void AFXAutoTriggerSingleton::RemoveActorByClass(AActor* Actor, UClass* ActorClass) {
}

void AFXAutoTriggerSingleton::ManuallyTriggerPrerequisite(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, bool& bResult, bool bTrigger) {
}

void AFXAutoTriggerSingleton::KillAutoTriggerFX(UObject* WorldContextObject, UObject* FXOwner, UFXAutoTriggerDefinitionAsset* FXAutoTriggerDefinition, bool& bResult) {
}

void AFXAutoTriggerSingleton::IsManualPrerequisiteTriggered(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, bool& bResult) {
}

void AFXAutoTriggerSingleton::HasManualActor(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool& bResult) {
}

void AFXAutoTriggerSingleton::HasAutoTriggerFX(UObject* WorldContextObject, UObject* FXOwner, UFXAutoTriggerDefinitionAsset* FXAutoTriggerDefinition, bool& bResult) {
}

void AFXAutoTriggerSingleton::GetWorldCustomCondition(UObject* WorldContextObject, FName WorldConditionName, bool& bEnabled) {
}

void AFXAutoTriggerSingleton::GetEffectIsActive(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool& bIsActive) {
}

void AFXAutoTriggerSingleton::GetEffectHandle(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, FMultiFX2Handle& FXHandle) {
}

void AFXAutoTriggerSingleton::GetAnyEffectIsActive(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, bool& bAnyIsActive) {
}

void AFXAutoTriggerSingleton::GetActorCustomCondition(AActor* Actor, FName ActorConditionName, bool& bEnabled) {
}

void AFXAutoTriggerSingleton::EffectUpdatesDisabled(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool& bIsDisabled) {
}

void AFXAutoTriggerSingleton::EffectParameterUpdatesDisabled(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, FName Parameter, bool& bIsDisabled) {
}

void AFXAutoTriggerSingleton::DisableEffectUpdates(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool bDisableUpdates, bool& bResult) {
}

void AFXAutoTriggerSingleton::DisableEffectParameterUpdates(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, FName Parameter, bool bDisableUpdates, bool& bResult) {
}

void AFXAutoTriggerSingleton::AddManualActors(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, TArray<AActor*> Actors, bool& bResult) {
}

void AFXAutoTriggerSingleton::AddManualActor(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool& bResult) {
}

void AFXAutoTriggerSingleton::AddCustomBucketActor(AActor* Actor, FName CustomBucket) {
}

void AFXAutoTriggerSingleton::AddAutoTriggerFX(UObject* WorldContextObject, UObject* FXOwner, UFXAutoTriggerDefinitionAsset* FXAutoTriggerDefinition, bool& bResult) {
}

void AFXAutoTriggerSingleton::AddActorByClass(AActor* Actor, UClass* ActorClass, FName ClassTag) {
}

void AFXAutoTriggerSingleton::ActorIsInCustomBucket(AActor* Actor, FName CustomBucket, bool& bIsIn) {
}

AFXAutoTriggerSingleton::AFXAutoTriggerSingleton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Globals = NULL;
}

