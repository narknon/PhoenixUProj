#include "SocialAgentPawnComponent.h"

class AActor;

void USocialAgentPawnComponent::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

USocialAgentPawnComponent::USocialAgentPawnComponent() {
    this->m_avoidLOD = 3;
}

