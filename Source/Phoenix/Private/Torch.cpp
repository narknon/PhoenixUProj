#include "Torch.h"
#include "Components/StaticMeshComponent.h"

class AActor;
class UAkComponent;
class UAnimatedLightComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UObjectStateComponent;
class UPointLightComponent;
class UPrimitiveComponent;
class USphereComponent;
class USpotLightComponent;
class UTimelineComponent;

bool ATorch::TorchSetup(UObjectStateComponent* i_ObjectStateComp, UTimelineComponent* i_Timeline, UNiagaraComponent* i_FireParticle, USphereComponent* i_PropagateTrigger, UAkComponent* i_AkComp, UAnimatedLightComponent* i_AnimatedLight, UPointLightComponent* i_PL, USpotLightComponent* i_SL, UPointLightComponent* i_IL) {
    return false;
}

void ATorch::TorchGetNormalizedTime(float& NormalizedTime) const {
}


void ATorch::StartLight(bool bLerp) {
}

bool ATorch::ShouldStartLit_Implementation() {
    return false;
}

void ATorch::SetUpLights(UPointLightComponent* curPL, USpotLightComponent* curSL, UPointLightComponent* curIL) {
}

void ATorch::SetOnFire(bool bOnFire) {
}

void ATorch::SequentialLightTimelineUpdate(FVector LightLoc, float Percent) {
}

void ATorch::SequentialLightTimelineFinish() {
}

void ATorch::SequentialLight_Implementation(FVector LightLoc) {
}

void ATorch::ResetLightColor() {
}


void ATorch::Propagate() {
}


void ATorch::OnProxOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ATorch::OnPropagateOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ATorch::OnPropagateOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

uint8 ATorch::ModFunctionSetup_Implementation() {
    return 0;
}

void ATorch::MidLight() {
}

void ATorch::LoadSyncronousNiagaraSystem(TSoftObjectPtr<UNiagaraSystem> UnloadedSystem, UNiagaraSystem*& LoadedSystem) {
}

void ATorch::LightswitchTimelineUpdate(float Percent) {
}


void ATorch::Lightswitch(bool bOn, bool bLerp) {
}

FTransform ATorch::GetDPCInitialTransform() {
    return FTransform{};
}

void ATorch::ExtinguishLight_Implementation(bool bSlow) {
}

void ATorch::EndLight_Implementation(bool bLerp) {
}

void ATorch::CrossLightTickRange(bool bin) {
}


void ATorch::ChangeLightColor(FLinearColor i_Color, float i_temperature) {
}

ATorch::ATorch(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bStartLit = true;
    this->bUseMesh = true;
    this->bSimulatePhysics = false;
    this->bStartAsleep = true;
    this->bTargetable = false;
    this->bLightTemperature = true;
    this->LightTemperature = 2650.00f;
    this->bPropagate = true;
    this->bCustomPropagateRadius = false;
    this->CustomPropagateRadius = 100.00f;
    this->bReceiveSequentialLighting = false;
    this->bSendSequentialLighting = false;
    this->SequentialLightSpreadRadius = 650.00f;
    this->bLightProxPlayer = false;
    this->ProxToPlayer = 5.00f;
    this->bAncientMagic = false;
    this->bExternalBoiler = false;
    this->bCastShadow = true;
    this->bCastVolumetricShadow = false;
    this->bCastShadowOnlyFromStaticObjects = false;
    this->PointLightUnit = ELightUnits::Unitless;
    this->PointLightIntensity = 1500.00f;
    this->PointLightOffIntensity = 0.00f;
    this->CustomLightRadius = 700.00f;
    this->SourceRadius_PL = 0.00f;
    this->ShadowResolution_PL = 0.50f;
    this->ContactShadowLength_PL = 0.00f;
    this->MSRShadowCaster_PL = -1.00f;
    this->VolumetricScattering_PL = 1.00f;
    this->IndirectLighting_PL = 1.00f;
    this->MinDistance_PL = 0.00f;
    this->MaxDrawDistance_PL = 0.00f;
    this->bCustomLightPosition = false;
    this->bCustomLightRotation = false;
    this->bUseLightTexture = false;
    this->LightTexture = NULL;
    this->bSpotlight = false;
    this->bSpotlightShadow = true;
    this->bSpotlightVolumetricShadow = false;
    this->bSpotlightCastShadowOnlyFromStaticObjects = false;
    this->SpotlightUnit = ELightUnits::Unitless;
    this->SpotlightIntensity = 5000.00f;
    this->AttenuationRadius_SL = 1000.00f;
    this->SourceRadius_SL = 0.00f;
    this->ShadowResolution_SL = 1.00f;
    this->ShadowBias_SL = 0.10f;
    this->ShadowSlopeBias_SL = 0.10f;
    this->InnerConeAngle = 0.00f;
    this->OuterConeAngle = 60.00f;
    this->ContactShadowLength_SL = 0.00f;
    this->MSRShadowCaster_SL = -1.00f;
    this->VolumetricScattering_SL = 1.00f;
    this->IndirectLighting_SL = 1.00f;
    this->MaxDrawDistance_SL = 0.00f;
    this->bUseLightTexture_SL = false;
    this->SpotlightTexture = NULL;
    this->bIndirectLight = false;
    this->IndirectLightUnit = ELightUnits::Unitless;
    this->IndirectIntensity = 900.00f;
    this->CustomLightRadius_IL = 300.00f;
    this->MaxDrawDistance_IL = 0.00f;
    this->bCustomFireParticle = false;
    this->CustomFireParticle = NULL;
    this->WaveSpeed1 = 3.50f;
    this->WaveSpeed2 = 6.00f;
    this->MinIntensity = 0.60f;
    this->IntensityNoiseSpeed = 0.50f;
    this->IntensityNoiseFactor = 0.10f;
    this->bDayNightModulate = false;
    this->DayIntensityMod = 100.00f;
    this->NightIntensityMod = 1.00f;
    this->TorchMeshComp = Cast<UStaticMeshComponent>(GetDefaultSubobjectByName(TEXT("StaticMeshComponent0")));
    this->PointLightComp = NULL;
    this->SpotLightComp = NULL;
    this->IndirectLightComp = NULL;
    this->AnimatedLightComp = NULL;
    this->LightControllerComp = NULL;
    this->AkComp = NULL;
    this->ParticleComp = NULL;
    this->PropagateSphere = NULL;
    this->ProximitySphere = NULL;
    this->LightLerp_Timeline = NULL;
    this->Ak_Light = NULL;
    this->Ak_Extinguish = NULL;
    this->bIsLit = true;
    this->bLightTick = true;
    this->bMovable = false;
    this->bCanSound = false;
    this->TorchObjectState = NULL;
    this->PreviousPLUnit = ELightUnits::Unitless;
    this->PreviousSLUnit = ELightUnits::Unitless;
    this->PreviousILUnit = ELightUnits::Unitless;
}

