#include "CharacterLightingFeaturesSettings.h"

FCharacterLightingFeaturesSettings::FCharacterLightingFeaturesSettings() {
    this->CharacterProjectedShadowsEndMeters = 0.00f;
    this->MaxCharacterProjectedShadows = 0;
    this->CapsuleShadowsEndMeters = 0.00f;
    this->MaxCharacterCapsuleShadows = 0;
    this->CharacterContactShadowsStartMeters = 0.00f;
    this->CharacterContactShadowsEndMeters = 0.00f;
    this->MaxCharacterContactShadows = 0;
    this->BlobShadowsEndMeters = 0.00f;
    this->MaxCharacterBlobShadows = 0;
    this->CharacterIndirectCapsuleShadowsEndMeters = 0.00f;
    this->CapsuleIndirectShadowMinVisibility = 0.00f;
    this->MaxCharacterIndirectCapsuleShadows = 0;
    this->CharacterLightChannelEndMeters = 0.00f;
    this->MaxCharactersInLightChannel = 0;
    this->bLimitCharacterProjectedShadows = false;
    this->bLimitCharacterCapsuleShadows = false;
    this->bLimitCharactersInLightChannel = false;
    this->bEnableCharacterIndirectCapsuleShadows = false;
    this->bLimitCharacterIndirectCapsuleShadows = false;
    this->bLimitCharacterContactShadows = false;
    this->bUseCharacterContactShadowsStart = false;
    this->bUseCharacterContactShadowsEnd = false;
    this->bDisablePlayerContactShadows = false;
    this->bEnableCharacterBlobShadows = false;
    this->bLimitCharacterBlobShadows = false;
}

