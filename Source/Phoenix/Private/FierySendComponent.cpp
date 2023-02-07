#include "FierySendComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class AMunitionType_Base;
class UMultiFX2Asset;

void UFierySendComponent::HandleActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

void UFierySendComponent::AddFierySendComponent(AActor* Actor, AActor* InInstigator, UMultiFX2Asset* InHitFx, TSubclassOf<AMunitionType_Base> InMunitionClass, bool bInDestroyOnHit) {
}

UFierySendComponent::UFierySendComponent() {
    this->HitFx = NULL;
    this->MunitionClass = NULL;
    this->bDestroyOnHit = false;
    this->Instigator = NULL;
}

