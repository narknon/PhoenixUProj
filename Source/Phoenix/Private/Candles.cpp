#include "Candles.h"
#include "Components/StaticMeshComponent.h"

class UAnimatedLightComponent;
class UObjectStateComponent;
class UPointLightComponent;
class USpotLightComponent;

void ACandles::SetUpLights(UPointLightComponent* curPL, USpotLightComponent* curSL) {
}

void ACandles::ResetLightColor() {
}

void ACandles::CrossLightTickRange(bool bin) {
}

void ACandles::ChangeLightColor(FLinearColor i_Color, float i_temperature) {
}

bool ACandles::CandleSetup(UObjectStateComponent* i_ObjectStateComp, uint8 i_CandleType, UAnimatedLightComponent* i_AnimatedLight, UPointLightComponent* i_PL, USpotLightComponent* i_SL) {
    return false;
}

ACandles::ACandles() : AStaticMeshActor(FObjectInitializer::Get()) {
    this->bStartLit = true;
    this->bGIOnlyLight = false;
    this->bSimulatePhysics = false;
    this->bStartAsleep = true;
    this->bDestructible = false;
    this->bLightTemperature = true;
    this->LightTemperature = 3000.00f;
    this->bCastShadow = true;
    this->bCastVolumetricShadow = false;
    this->PointLightUnit = ELightUnits::Unitless;
    this->PointLightIntensity = 200.00f;
    this->CustomLightRadius = 250.00f;
    this->SourceRadius_PL = 0.00f;
    this->ShadowResolution_PL = 0.20f;
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
    this->bSpotlightVolumetricShadow = false;
    this->SpotlightUnit = ELightUnits::Unitless;
    this->SpotlightIntensity = 1000.00f;
    this->AttenuationRadius_SL = 700.00f;
    this->SourceRadius_SL = 0.00f;
    this->ShadowResolution_SL = 0.50f;
    this->ShadowBias_SL = 0.10f;
    this->ShadowSlopeBias_SL = 0.10f;
    this->InnerConeAngle = 0.00f;
    this->OuterConeAngle = 60.00f;
    this->ContactShadowLength_SL = 0.00f;
    this->MSRShadowCaster_SL = -1.00f;
    this->VolumetricScattering_SL = 1.00f;
    this->IndirectLighting_SL = 1.00f;
    this->MaxDrawDistance_SL = 0.00f;
    this->WaveSpeed1 = 3.50f;
    this->WaveSpeed2 = 6.00f;
    this->MinIntensity = 0.60f;
    this->IntensityNoiseSpeed = 0.50f;
    this->IntensityNoiseFactor = 0.10f;
    this->bDayNightModulate = false;
    this->DayIntensityMod = 100.00f;
    this->NightIntensityMod = 1.00f;
    this->CandleMeshComp = Cast<UStaticMeshComponent>(GetDefaultSubobjectByName(TEXT("StaticMeshComponent0")));
    this->PointLightComp = NULL;
    this->SpotLightComp = NULL;
    this->AnimatedLightComp = NULL;
    this->LightControllerComp = NULL;
    this->CandleObjectState = NULL;
    this->bMovable = false;
    this->NoGlowMaterial = NULL;
    this->PreviousPLUnit = ELightUnits::Unitless;
    this->PreviousSLUnit = ELightUnits::Unitless;
}

