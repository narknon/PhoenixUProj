#include "DrainingDraughtEffect.h"
#include "Components/SphereComponent.h"

class AActor;
class ADraingingDraughtOrb;
class UPrimitiveComponent;

void ADrainingDraughtEffect::Tick(float DeltaSeconds) {
}

void ADrainingDraughtEffect::SpawnOrbs() {
}

void ADrainingDraughtEffect::SetNumberOrbs(int32 NumOrbs) {
}

void ADrainingDraughtEffect::SendOutOrb() {
}

void ADrainingDraughtEffect::OnOverlapEndSeekSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ADrainingDraughtEffect::OnOverlapEndCloudSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ADrainingDraughtEffect::OnOverlapBeginSeekSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ADrainingDraughtEffect::OnOverlapBeginCloudSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

ADraingingDraughtOrb* ADrainingDraughtEffect::GetBestAvailableOrb(AActor* Target) {
    return NULL;
}

void ADrainingDraughtEffect::DoAOECloudDamageCallback() {
}

void ADrainingDraughtEffect::BeginPlay() {
}

ADrainingDraughtEffect::ADrainingDraughtEffect() {
    this->m_CloudRadius = 500.00f;
    this->m_AOEDamage = 30.00f;
    this->m_AOEDamageRate = 0.50f;
    this->m_SeekRadius = 1000.00f;
    this->m_SeekTime = 2.00f;
    this->m_OrbDistance = 100.00f;
    this->m_OrbGroundDist = 75.00f;
    this->m_OrbRotationRate = 10.00f;
    this->m_NumOrbs = 3;
    this->m_OrbDamage = 100.00f;
    this->m_bTimingBasedOnOrbAmt = true;
    this->m_BufferTime = 4.00f;
    this->m_OrbIncreaseAmt = 1;
    this->m_OrbMunition = NULL;
    this->m_OrbSeekSphere = CreateDefaultSubobject<USphereComponent>(TEXT("OrbSeekSphere"));
    this->m_CloudDamageSphere = NULL;
}

