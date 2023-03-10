#include "LightCullingSettings.h"

ULightCullingSettings::ULightCullingSettings() {
    this->DistanceOverride = ELightCullingDistanceOverride::OnlyIfNotSet;
    this->MaxDrawDistanceMeters = 40.00f;
    this->MaxDistanceFadeRangeMeters = 3.00f;
    this->AutoMaxDistanceFadeRangePercentage = 10.00f;
    this->SuspiciouslyLargeMaxDrawDistanceMeters = 500.00f;
    this->MovableShadowsStartDistanceMeters = 20.00f;
    this->LimitMovableShadowCastingLights = 3;
    this->NonMovableShadowsStartDistanceMeters = 75.00f;
    this->LimitNonMovableShadowCastingLights = 16;
    this->AffectVolumetricLightingStartDistanceMeters = 60.00f;
    this->LimitAffectVolumetricLightingLights = 8;
    this->VolumetricScatteringDistanceMeters = 35.00f;
    this->VolumetricScatteringFadeRangeMeters = 3.00f;
    this->LimitVolumetricScatteringLights = 4;
    this->VolumetricShadowStartDistanceMeters = 35.00f;
    this->LimitVolumetricShadowingLights = 8;
    this->AffectTranslucentLightingStartDistanceMeters = 25.00f;
    this->LimitAffectTranslucentLightingLights = 8;
    this->ContactShadowsStartDistanceMeters = 35.00f;
    this->LimitContactShadowingLights = 2;
    this->MoveableLightStartDistanceMeters = 35.00f;
    this->LimitMoveableLights = 8;
    this->TickingLightStartDistanceMeters = 0.00f;
    this->CharacterProjectedShadowsEndMeters = 20.00f;
    this->MaxCharacterProjectedShadows = 3;
    this->CapsuleShadowsEndMeters = 45.00f;
    this->MaxCharacterCapsuleShadows = 8;
    this->CharacterContactShadowsStartMeters = 4.00f;
    this->CharacterContactShadowsEndMeters = 90.00f;
    this->MaxCharacterContactShadows = 64;
    this->BlobShadowsEndMeters = 75.00f;
    this->MaxCharacterBlobShadows = 32;
    this->CharacterIndirectCapsuleShadowsEndMeters = 4.00f;
    this->CapsuleIndirectShadowMinVisibility = 0.10f;
    this->MaxCharacterIndirectCapsuleShadows = 8;
    this->CharacterLightChannelEndMeters = 30.00f;
    this->MaxCharactersInLightChannel = 8;
    this->DistanceCulledUpdateMarginMeters = 8.00f;
    this->bControlMovableShadowsStart = true;
    this->bControlNonMovableShadowsStart = true;
    this->bControlVolumetricIntensity = true;
    this->bControlVolumetricShadow = true;
    this->bControlAffectVolumetricLighting = true;
    this->bControlAffectTranslucentLighting = true;
    this->bControlContactShadows = true;
    this->bControlMoveable = true;
    this->bControlTicking = true;
    this->bAutoMaxDistanceFadeRangePercentage = false;
    this->bLimitMovableShadowCastingLights = true;
    this->bLimitNonMovableShadowCastingLights = true;
    this->bLimitVolumetricScatteringLights = true;
    this->bLimitVolumetricShadowingLights = true;
    this->bLimitAffectVolumetricLighting = false;
    this->bLimitAffectTranslucentLighting = false;
    this->bLimitContactShadowingLights = true;
    this->bLimitMoveableLights = true;
    this->bLimitCharacterProjectedShadows = true;
    this->bLimitCharacterCapsuleShadows = true;
    this->bLimitCharactersInLightChannel = false;
    this->bEnableCharacterIndirectCapsuleShadows = false;
    this->bLimitCharacterIndirectCapsuleShadows = true;
    this->bLimitCharacterContactShadows = false;
    this->bUseCharacterContactShadowsStart = false;
    this->bUseCharacterContactShadowsEnd = false;
    this->bDisablePlayerContactShadows = false;
    this->bEnableCharacterBlobShadows = false;
    this->bLimitCharacterBlobShadows = true;
    this->bEnableCharacterFadeOut = false;
    this->bUseTrueLightShapes = true;
}

