#include "DevilsSnare.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

class AActor;
class UPrimitiveComponent;

void ADevilsSnare::UpdateMeshMaterial() {
}

void ADevilsSnare::StopRecoiling() {
}

void ADevilsSnare::StartRecoil(float RecoilPercent) {
}

void ADevilsSnare::Reveal() {
}

void ADevilsSnare::PlayerLumosStart() {
}

void ADevilsSnare::PlayerLumosEnd() {
}

void ADevilsSnare::OnOverlapEndForLightAndFire(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ADevilsSnare::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ADevilsSnare::OnOverlapBeginForLightAndFire(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ADevilsSnare::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ADevilsSnare::HitBySpell(float RecoilPercent) {
}

void ADevilsSnare::DodgeStop(AActor* InPlayer) {
}

void ADevilsSnare::DelayedSetup() {
}

ADevilsSnare::ADevilsSnare(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    this->TypeIndex = -1;
    this->bCanAffectPlayer = true;
    this->bStartsHidden = false;
    this->DamagePerSecond = 25.00f;
    this->RecoilPercentForLumos = 0.01f;
    this->RecoilPercentForIncendio = 0.50f;
    this->RecoilPercentForConfringo = 0.50f;
    this->RecoilPercentForAvadaKedavra = 0.50f;
    this->FireRecoilDistance = 1000.00f;
    this->GrowBackSpeed = 0.00f;
    this->RevealTime = 2.00f;
    this->TimeBeforeRegrowing = 2.00f;
    this->IncreaseRadiusForLightAndFireCheck = 0.00f;
    this->DodgeInterpolatePercent = 0.10f;
    this->MinPlayerSpeed = 0.00f;
    this->CurvePlayerSpeedReductionPerSecond = NULL;
    this->PlayerDiesOnMinSpeedReached = false;
    this->CurrentPercent = 1.00f;
    this->CurrentState = EDevilsSnareState::Idle;
    this->ActualGrowthPercent = 1.00f;
    this->bPlayerIsUsingLumos = false;
    this->LightAndFireCheckVolumeComponent = CreateDefaultSubobject<USphereComponent>(TEXT("LightAndFireCheckVolume"));
    this->AreaOfEffectVolumeComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("AreaOfEffectVolume"));
    this->bOverrideBounds = false;
}

