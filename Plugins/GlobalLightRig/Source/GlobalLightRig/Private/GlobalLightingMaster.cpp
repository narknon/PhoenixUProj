#include "GlobalLightingMaster.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/SkyAtmosphereComponent.h"
#include "Components/SkyLightComponent.h"
#include "SkyOnlyComponent.h"

class AGlobalLightingMaster;
class UGlobalLightingDefaults;
class UObject;

void AGlobalLightingMaster::SetCinematicDefaults(UObject* WorldContextObject, UGlobalLightingDefaults* CinematicDefaults) {
}

void AGlobalLightingMaster::GetGlobalLightingMaster(UObject* WorldContextObject, AGlobalLightingMaster*& GlobalLightingMaster) {
}

void AGlobalLightingMaster::GetCinematicDefaults(UObject* WorldContextObject, UGlobalLightingDefaults*& CinematicDefaults) {
}

void AGlobalLightingMaster::ClearCinematicDefaults(UObject* WorldContextObject) {
}

void AGlobalLightingMaster::CheckWorld() {
}

void AGlobalLightingMaster::CaptureSkyLight() {
}

AGlobalLightingMaster::AGlobalLightingMaster() {
    this->SkyAtmosphereHeightOffsetMeters = -250.00f;
    this->UseExternalLightingComponents = 32;
    this->ControlLightingComponents = 61;
    this->HideExtraLightingComponents = 21;
    this->ControlFeatures = 251;
    this->SkyLightZOffsetMeters = 1.00f;
    this->SkyLightMoveThresholdMeters = 10.00f;
    this->SkyLightUpdateThresholdSeconds = 0.10f;
    this->SkyLightAge = 0.00f;
    this->Priority = 0.00f;
    this->bBounded = false;
    this->bIsMaster = false;
    this->DirectionalLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("InternalDirectionalLight"));
    this->SecondaryDirectionalLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("InternalSecondaryDirectionalLight"));
    this->SkyLightComponent = CreateDefaultSubobject<USkyLightComponent>(TEXT("InternalSkyLight"));
    this->ExpHeightFogComponent = CreateDefaultSubobject<UExponentialHeightFogComponent>(TEXT("InternalExponentialHeightFog"));
    this->SkyAtmosphereComponent = CreateDefaultSubobject<USkyAtmosphereComponent>(TEXT("InternalSkyAtmosphere"));
    this->SkyAtmosphereSkyOnlyComponent = CreateDefaultSubobject<USkyOnlyComponent>(TEXT("InternalSkyOnly"));
    this->PostProcessComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("InternalProbeLighting"));
}

