#include "MunitionType_AOE_MultiFX.h"

void AMunitionType_AOE_MultiFX::TriggerWarningStart() {
}

void AMunitionType_AOE_MultiFX::TriggerWarningLoop() {
}

void AMunitionType_AOE_MultiFX::TriggerWarning() {
}

void AMunitionType_AOE_MultiFX::TriggerImpactEnd() {
}

void AMunitionType_AOE_MultiFX::TriggerImpact(bool bSkipStartState) {
}

void AMunitionType_AOE_MultiFX::TriggerFizzle() {
}

void AMunitionType_AOE_MultiFX::TriggerExplode() {
}

void AMunitionType_AOE_MultiFX::TriggerEnd() {
}

void AMunitionType_AOE_MultiFX::TriggerArresto() {
}

void AMunitionType_AOE_MultiFX::TriggerAnnounceLoop() {
}





bool AMunitionType_AOE_MultiFX::IsArresto() {
    return false;
}

FMultiFX2Handle AMunitionType_AOE_MultiFX::GetWarningFXHandle() const {
    return FMultiFX2Handle{};
}

FMultiFX2Handle AMunitionType_AOE_MultiFX::GetFizzleFXHandle() const {
    return FMultiFX2Handle{};
}

FMultiFX2Handle AMunitionType_AOE_MultiFX::GetExplodeFXHandle() const {
    return FMultiFX2Handle{};
}

FMultiFX2Handle AMunitionType_AOE_MultiFX::GetAnnounceFXHandle() const {
    return FMultiFX2Handle{};
}

void AMunitionType_AOE_MultiFX::EndArresto() {
}

void AMunitionType_AOE_MultiFX::Cancel() {
}

AMunitionType_AOE_MultiFX::AMunitionType_AOE_MultiFX() {
    this->MinDamage = 0.00f;
    this->CharacterDamage = -1.00f;
    this->m_radiusStart = 100.00f;
    this->m_radiusEnd = 1000.00f;
    this->bUseCustomGrowthDuration = false;
    this->CustomGrowthDuration = 0.50f;
    this->m_hitVictimInterval = 10.00f;
    this->CollisionChannel = ECC_GameTraceChannel3;
    this->m_damageType = NULL;
    this->PhysicsImpulse = 0.00f;
    this->PhysicsAngularImpulse = 0.00f;
    this->bOnlyTestDamageOnce = false;
    this->bUnblockable = false;
    this->bBreakBlockFX = true;
    this->bAffectCompanions = true;
    this->bAffectCharacters = true;
    this->bOnlyAffectCharactersOfHostileTeams = false;
    this->bAffectObjects = true;
    this->bTransformedCharactersAffectedLikeCharacters = false;
    this->bRespectInstigatorCanHit = false;
    this->bTriggerNPCResponse = false;
    this->bRespectCover = false;
    this->bCalculatePositionOnce = false;
    this->ComboType = EComboType::None;
    this->AnnounceTime = 0.00f;
    this->AnnounceHomingSpeed = 0.00f;
    this->bKeepAnnounceStartRunning = false;
    this->bForceAnnounceStartEndOnCancel = false;
    this->AnnounceMotionFX = NULL;
    this->bRequireTriggerToWarn = false;
    this->WarningTime = 0.00f;
    this->WarningHomingSpeed = 0.00f;
    this->WarningMotionFX = NULL;
    this->bRequireTriggerToExplode = false;
    this->ExplosionFX_EndImmediately = true;
    this->ExplosionStartTime = 0.00f;
    this->ExplosionEndTime = 0.00f;
    this->ExplosionMotionFX = NULL;
    this->PlayExplosionOnGround = false;
    this->m_stopAtCollision = true;
    this->FireNoiseSize = ENoiseSize::NoNoise;
    this->ImpactNoiseSize = ENoiseSize::NoNoise;
    this->bThrowTarget = false;
    this->TargetHalfAngleXY = 15;
    this->TargetHalfAngleZ = 45;
    this->LaunchAngle = 12.00f;
    this->InAirLaunchAngle = 0.00f;
    this->MaximumLaunchAngle = 30.00f;
    this->HeightAdjustment = 0.00f;
    this->LevelMinZThreshold = -150.00f;
    this->LevelMaxZThreshold = 0.00f;
    this->BasePhysicsImpulse = 0.00f;
    this->MassScaledPhysicsImpulse = 2000.00f;
    this->CharacterBasePhysicsImpulse = 0.00f;
    this->CharacterMassScaledPhysicsImpulse = 2000.00f;
    this->MaxVelocity = 2500.00f;
    this->TargetingPercent = 100;
    this->bUpdateTarget = true;
    this->LeviosoImpulseScale = 1.00f;
    this->MinDamageDealt = -1.00f;
    this->MaxDamageDealt = -1.00f;
    this->MinDamageDealtCharacter = -1.00f;
    this->MaxDamageDealtCharacter = -1.00f;
    this->MinDamageTaken = -1.00f;
    this->MaxDamageTaken = -1.00f;
    this->MinDamageTakenCharacter = -1.00f;
    this->MaxDamageTakenCharacter = -1.00f;
    this->MinDamageTakenCharacterWall = -1.00f;
    this->MaxDamageTakenCharacterWall = -1.00f;
    this->MinDamageTakenCharacterFloor = -1.00f;
    this->MaxDamageTakenCharacterFloor = -1.00f;
    this->MinDamageTakenCharacterCharacter = -1.00f;
    this->MaxDamageTakenCharacterCharacter = -1.00f;
    this->ArrestoTimeExtension = 4.00f;
    this->bTriggerMunitionSentMessage = false;
    this->AnnounceMotionComponent = NULL;
    this->WarningMotionComponent = NULL;
    this->ExplosionMotionComponent = NULL;
    this->SpellTool = NULL;
}

