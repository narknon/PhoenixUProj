#include "MasterTickThrottlerSingleton.h"

class AActor;
class UActorComponent;

void AMasterTickThrottlerSingleton::RemoveManagedComponent(UActorComponent* Component) {
}

void AMasterTickThrottlerSingleton::RemoveManagedActor(AActor* Actor) {
}

void AMasterTickThrottlerSingleton::IsManagedComponent(UActorComponent* Component, bool& bIsManaged) {
}

void AMasterTickThrottlerSingleton::IsManagedActor(AActor* Actor, bool& bIsManaged) {
}

void AMasterTickThrottlerSingleton::IsComponentThrottled(UActorComponent* Component, bool& bIsThrottled) {
}

void AMasterTickThrottlerSingleton::IsActorThrottled(AActor* Actor, bool& bIsThrottled) {
}

void AMasterTickThrottlerSingleton::EnableComponentThrottling(UActorComponent* Component, bool bEnable) {
}

void AMasterTickThrottlerSingleton::EnableActorThrottling(AActor* Actor, bool bEnable) {
}

void AMasterTickThrottlerSingleton::DisableComponentThrottling(UActorComponent* Component) {
}

void AMasterTickThrottlerSingleton::DisableActorThrottling(AActor* Actor) {
}

void AMasterTickThrottlerSingleton::AddManagedComponent(UActorComponent* Component, const FMasterTickThrottlerSettings& Settings) {
}

void AMasterTickThrottlerSingleton::AddManagedActor(AActor* Actor, const FMasterTickThrottlerSettings& Settings) {
}

AMasterTickThrottlerSingleton::AMasterTickThrottlerSingleton() {
    this->bLastEyeValid = false;
}

