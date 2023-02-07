#include "ObjectStateManager.h"

class AActor;
class ABase_Character;
class UCharacterStateInfo;
class UObject;
class UObjectStateInfo;
class UObjectStateManager;
class UReparoData;
class UWorld;

void UObjectStateManager::UpdateOriginalInfo(AActor* InActor) {
}

void UObjectStateManager::SetOriginalTransform(AActor* InActor, FTransform InTransform) {
}

void UObjectStateManager::OnActorEndPlay(AActor* DestroyedActor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason) {
}

bool UObjectStateManager::IsRevelioActor(AActor* InActor) {
    return false;
}

void UObjectStateManager::HighlightActorWithRevelio(AActor* InActor, bool bHighlight) {
}

UObjectStateManager* UObjectStateManager::GetObjectStateManager(const UObject* WorldContext) {
    return NULL;
}

UObjectStateInfo* UObjectStateManager::GetObjectStateInfo(const AActor* InActor) {
    return NULL;
}

int32 UObjectStateManager::GetDbUniqueId(const AActor* InActor) {
    return 0;
}

FName UObjectStateManager::GetDbSubType(const AActor* InActor) {
    return NAME_None;
}

FName UObjectStateManager::GetDbId(const AActor* InActor) {
    return NAME_None;
}

FName UObjectStateManager::GetDbClassId(const AActor* InActor) {
    return NAME_None;
}

UCharacterStateInfo* UObjectStateManager::GetCharacterStateInfo(const ABase_Character* InCharacter) {
    return NULL;
}

UObjectStateManager* UObjectStateManager::Get(UWorld* NewWorld) {
    return NULL;
}

void UObjectStateManager::EnableCcdForXSeconds(AActor* InActor, float Time) {
}

bool UObjectStateManager::EnableCcd(AActor* InActor) {
    return false;
}

void UObjectStateManager::EnableAutoRepair(UObject* InObject, float MinRepairDelay, float MaxRepairDelay, UReparoData* ReparoDataOverride) {
}

void UObjectStateManager::DisableAutoRepair(UObject* InObject) {
}

UObjectStateManager::UObjectStateManager() {
    this->ContextFilterComponent = NULL;
}

