#include "TwisterMixtureEffect.h"
#include "Components/SphereComponent.h"

class AActor;
class AMunitionType_Base;
class UPrimitiveComponent;

void ATwisterMixtureEffect::Tick(float DeltaSeconds) {
}

void ATwisterMixtureEffect::OnOverlapEndStoppingSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ATwisterMixtureEffect::OnCharacterLand(const FHitResult& Hit) {
}

void ATwisterMixtureEffect::Cleanup(AMunitionType_Base* MunitionInstance) {
}

void ATwisterMixtureEffect::BeginPull() {
}

void ATwisterMixtureEffect::BeginPlay() {
}

ATwisterMixtureEffect::ATwisterMixtureEffect() {
    this->m_PullRadius = 1200.00f;
    this->m_StopRadius = 150.00f;
    this->m_PullTime = 2.00f;
    this->m_PullDelay = 1.00f;
    this->m_TwisterImpulseMultiplier = 10.00f;
    this->m_UpgradeRadiusMultiplier = 1.10f;
    this->m_TwisterEffectSphere = CreateDefaultSubobject<USphereComponent>(TEXT("TwisterEffectSphere"));
    this->m_TwisterStoppingSphere = CreateDefaultSubobject<USphereComponent>(TEXT("TwisterStoppingSphere"));
}

