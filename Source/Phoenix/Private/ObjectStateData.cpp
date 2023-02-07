#include "ObjectStateData.h"

FObjectStateData::FObjectStateData() {
    this->HitSfx = NULL;
    this->m_baseHealth = 0.00f;
    this->m_minDamageThreshold = 0.00f;
    this->OverrideMass = 0.00f;
    this->MinOptimumAvatarDistance = 0.00f;
    this->MaxOptimumAvatarDistance = 0.00f;
    this->bIsPersistent = false;
    this->bDamagable = false;
    this->bNoDamageBreakable = false;
    this->bImmuneToSpells = false;
    this->bCanBecomeMovable = false;
    this->bHighlightWhenBroken = false;
    this->m_important = false;
    this->bRevelioResource = false;
    this->m_hidden = false;
    this->bExplode = false;
    this->bExplodeOnFire = false;
    this->bTransformable = false;
    this->bStartBroken = false;
    this->bTargetable = false;
    this->bSpecialTargetPerception = false;
    this->bIgnoreLimitedCountRules = false;
    this->bIgnoreActorHit = false;
    this->bIgnoreMunitionImpact = false;
    this->bTakeDamageFromCharacterCollisions = false;
    this->bFragile = false;
    this->bDamagableInPieces = false;
    this->bTreatAsCharacterForDamage = false;
    this->bDieInWater = false;
    this->bNeverAffectNavmesh = false;
    this->bNavOverrideMobilityCheck = false;
    this->bShowTargetUI = false;
    this->bCurrentlyTargetedUI = false;
    this->WidgetType = EWidgetType::WT_Social;
    this->PriorityLaunchTarget = 0;
    this->ImpactTypeOverride = EImpactTypes::None;
    this->BaseSizeClass = EObjectSizeClass::XXS;
}

