#include "SpellUpgradeParameters.h"

FSpellUpgradeParameters::FSpellUpgradeParameters() {
    this->Range = 0.00f;
    this->CooldownTime = 0.00f;
    this->NonCombatCooldownMultiplier = 0.00f;
    this->DamageObject = 0.00f;
    this->DamageCharacter = 0.00f;
    this->PhysicsImpulseSuccess = 0.00f;
    this->PhysicsImpulseFailed = 0.00f;
    this->Duration = 0.00f;
    this->DurationCharacter = 0.00f;
    this->DurationCreature = 0.00f;
    this->DurationPlayer = 0.00f;
    this->ChargeTime = 0.00f;
    this->ChargedMaxTime = 0.00f;
    this->ChannelingMinTime = 0.00f;
    this->CastNoiseIntensity = EGameEvent_Intensity::None;
    this->CastNoiseRadius = 0.00f;
    this->ImpactNoiseIntensity = EGameEvent_Intensity::None;
    this->ImpactNoiseRadius = 0.00f;
    this->ProjectileSpeed = 0.00f;
    this->ProjectileGravity = 0.00f;
    this->LimitedCountObject = 0;
    this->LimitedCountCharacter = 0;
    this->ImpactType = EImpactTypes::None;
    this->SizeLimit = EObjectSizeClass::XXS;
    this->EnemyShieldBreaker = EEnemyShieldBreaker::None;
    this->Affect = 0;
    this->AllowNonObjectInfoActors = false;
    this->UpgradedMechanics = false;
    this->PlayObjectImpactEffects = false;
    this->PlayerShieldBreaker = false;
    this->BeastCapture = false;
}

