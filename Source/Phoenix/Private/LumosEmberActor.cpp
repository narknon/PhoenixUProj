#include "LumosEmberActor.h"

class AActor;
class AAmbulatory_Character;
class UMaterialSwapMeshStatesFireAndForgetComponent;

void ALumosEmberActor::UpdateLumosFlicker(float DeltaTime, bool bIsFading) {
}

void ALumosEmberActor::RefreshCurrentScalabilitySettings() {
}

UMaterialSwapMeshStatesFireAndForgetComponent* ALumosEmberActor::GetScalabilityMeshStatesComponent() const {
    return NULL;
}

void ALumosEmberActor::GetLumosFlicker(float& IntensityMultiplier) const {
}

void ALumosEmberActor::ExternallyStartLumosFlickerForActor(AActor* OnlyForOwningActor, bool& bMatchedOwner) {
}

void ALumosEmberActor::ExternallyStartLumosFlicker() {
}

void ALumosEmberActor::CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FVector AmountDisplaced, FRotator AmountRotated) {
}

void ALumosEmberActor::CacheLerpVolumeLumosVolumetricScatteringIntensity(float Value, bool bSuccess) {
}

void ALumosEmberActor::CacheLerpVolumeLumosEVAdjust(float Value, bool bSuccess) {
}

ALumosEmberActor::ALumosEmberActor() {
    this->ArcHeightMultiplierCurve = NULL;
    this->DistanceInFrontOfPlayer = 25.00f;
    this->HeightAbovePlayer = 110.00f;
    this->EmberSpeedMultiplierOfDistance = 1.80f;
    this->BreadcrumbHeightModSpeed = 10.00f;
    this->EmberLifeTime = 120.00f;
    this->FollowBone = TEXT("Hips");
    this->BreadcrumbTrailSegmentLength = 20.00f;
    this->MaxBreadcrumbs = 100;
    this->bDebug = false;
    this->bDisconnectedFromWand = false;
    this->FlickerCurve = NULL;
    this->FlickerCurveLoops = 10;
    this->EmberTrick = NULL;
}

