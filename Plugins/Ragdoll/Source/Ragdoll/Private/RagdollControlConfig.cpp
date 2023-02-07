#include "RagdollControlConfig.h"

URagdollControlConfig::URagdollControlConfig() {
    this->RagdollMeshCollisionProfile = TEXT("Ragdoll");
    this->RagdollMeshCollisionProfileAlive = TEXT("RagdollAlive");
    this->RagdollCapsuleCollisionProfile = TEXT("Death");
    this->NonRagdollMeshCollisionProfile = TEXT("NpcMesh");
    this->NonRagdollCapsuleCollisionProfile = TEXT("EnemyCapsule");
    this->BakedRagdollCollisionProfile = TEXT("BakedRagdoll");
    this->BakedMeshCollisionProfile = TEXT("BakedMesh");
    this->TargetPoseInterpSpeed = 0.00f;
    this->bCcdAlwaysOn = true;
    this->bSweepCapsule = false;
    this->bAdjustConstraintsToTargetPose = false;
    this->ArtificialGravityScale = 1.00f;
    this->GetupBlendDuration = 0.50f;
    this->GetupBlendDelay = 0.50f;
    this->InWaterRecoveryDelay = 1.25f;
    this->bCanGetupFromGround = true;
    this->bCanRecoverInAir = false;
    this->MinGetupBlendVelocity = 100.00f;
    this->MinGetupBlendAngularVelocity = 500.00f;
    this->GroundDetectionRaycastDistance = 50.00f;
    this->bPhysicsHovering = false;
    this->HoverGravityCompensation = 0.95f;
    this->bMonitorCenterOfMassForImpacts = false;
    this->ImpactCameraShake = NULL;
    this->ImpactCameraShakeScale = 1.00f;
    this->bBlendToKinematic = true;
    this->bSyncCapsule = true;
    this->bDebugDrawImpacts = false;
    this->bDebugDrawTargetPose = false;
    this->bDebugDrawPoseMatching = false;
    this->bDebugDrawBlends = false;
}

