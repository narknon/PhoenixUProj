#include "MaterialPermuterSingleton.h"

class AActor;
class UObject;

void AMaterialPermuterSingleton::SetLoadingTrigger(UObject* TriggerOwner, FName Trigger) {
}

void AMaterialPermuterSingleton::ProhibitActorFade(AActor* Actor, bool bProhibit) {
}

void AMaterialPermuterSingleton::PauseAllActorFading(UObject* WorldContextObject, bool bPause) {
}

void AMaterialPermuterSingleton::LoadingTriggerSet(FName Trigger, bool& bSet) {
}

void AMaterialPermuterSingleton::IsLoadingTriggerSet(UObject* TriggerOwner, FName Trigger, bool& bSet) {
}

bool AMaterialPermuterSingleton::IsAllActorFadingPaused(UObject* WorldContextObject) {
    return false;
}

bool AMaterialPermuterSingleton::IsActorFadeProhibited(AActor* Actor) {
    return false;
}

FName AMaterialPermuterSingleton::GetTriggerPropertyName(FMaterialPermuterLoadTriggerProperty TriggerProperty) {
    return NAME_None;
}

void AMaterialPermuterSingleton::ClearLoadingTrigger(UObject* TriggerOwner, FName Trigger) {
}

AMaterialPermuterSingleton::AMaterialPermuterSingleton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Library = NULL;
    this->LiveMaterials = NULL;
}

