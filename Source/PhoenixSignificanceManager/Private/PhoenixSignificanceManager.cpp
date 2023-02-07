#include "PhoenixSignificanceManager.h"

class AActor;
class UObject;
class UPhoenixSignificanceManager;

bool UPhoenixSignificanceManager::SetObjectSignficanceBias(const UObject* Object, ESignificanceBiasEnum SignificanceBias) {
    return false;
}

void UPhoenixSignificanceManager::OnRegisteredActorDestroyed(AActor* DestroyedActor) {
}

UPhoenixSignificanceManager* UPhoenixSignificanceManager::GetSignificanceManager(UObject* WorldContextObject) {
    return NULL;
}

float UPhoenixSignificanceManager::GetSignificance(const UObject* Object) const {
    return 0.0f;
}

UPhoenixSignificanceManager::UPhoenixSignificanceManager() {
    this->Budgeters.AddDefaulted(4);
}

