#include "OppugnoSpellTool.h"

class AActor;
class AMunitionType_Base;

void AOppugnoSpellTool::TriggerOnOppugnoImpact(AActor* InSrcActor, AActor* InTargetActor) {
}

void AOppugnoSpellTool::SetThrowTarget(FVector InLocation) {
}

void AOppugnoSpellTool::OnOppugnoMunitionImpact(AMunitionType_Base* MunitionInstance, const FMunitionImpactData& MunitionImpactData) {
}

void AOppugnoSpellTool::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

AOppugnoSpellTool::AOppugnoSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TargetIdentifyRadius = 100.00f;
    this->OppugnoAngularDamping = 0.00f;
    this->OppugnoLinearDamping = 10.00f;
    this->ClearActorTagAfterThrowTime = 0.50f;
    this->AdjustTargetHeight = 0.00f;
    this->RagdollImpulseScale = 1.00f;
    this->DisableCharacterCollisionTime = 1.00f;
    this->MinimumHoldTorque = 400.00f;
    this->PullMotionFX = NULL;
    this->ThrowMotionFX = NULL;
    this->ThrowTimeDilationCurve = NULL;
    this->bReplacePhysicsObjectWithMunitionOnThrow = false;
    this->MunitionToSpawn = NULL;
    this->MinDamageDealt = -1.00f;
    this->MaxDamageDealt = -1.00f;
    this->MinDamageDealtCharacter = -1.00f;
    this->MaxDamageDealtCharacter = -1.00f;
    this->MinDamageTaken = -1.00f;
    this->MaxDamageTaken = -1.00f;
    this->MinDamageTakenCharacter = -1.00f;
    this->MaxDamageTakenCharacter = -1.00f;
    this->InterpPositionSpeed = 5.00f;
    this->InterpRotationSpeed = 20.00f;
    this->MaximumCharacterSize = EObjectSizeClass::M;
    this->AttachedActor = NULL;
}

