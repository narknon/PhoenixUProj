#include "LumosScalabilitySettings.h"

FLumosScalabilitySettings::FLumosScalabilitySettings() {
    this->Lighting = ELumosLightingScenario::Legacy;
    this->LightRadiusFactor = 0.00f;
    this->EmissiveDecalRatio = 0.00f;
    this->CastShadowsThreshold = EShadowQualityLevels::Low;
    this->bRenderAsSimpleLight = false;
    this->bSkipSimpleLightDemotion = false;
    this->bProjectDynamicShadows = false;
    this->bCastStaticShadows = false;
    this->bCastDynamicShadows = false;
    this->bCastVolumetricShadow = false;
    this->bCastTranslucentShadows = false;
    this->bAffectVolumetricLighting = false;
    this->bCastRaytracedShadow = false;
    this->bWbDoNotCacheShadows = false;
    this->ContactShadows = ELumosContactShadows::None;
    this->ContactShadowLength = 0.00f;
    this->PostProcessing = NULL;
    this->MinDistance = 0.00f;
    this->OuterConeAngle = 0.00f;
    this->bCasterMeshStatesIncludeChildren = false;
    this->bUsePostProcessing = false;
    this->bOverride_MinDistance = false;
    this->bOverride_OuterConeAngle = false;
}

