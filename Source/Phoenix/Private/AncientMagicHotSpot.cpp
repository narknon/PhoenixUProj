#include "AncientMagicHotSpot.h"
#include "CognitionStimuliSourceComponent.h"

class AActor;
class UBTService_AvaAITree;
class UNiagaraSystem;
class UObject;

void AAncientMagicHotSpot::UpdateVFX(float AngleRatio, float DistanceRatio) {
}





void AAncientMagicHotSpot::UnHide_Implementation() {
}

void AAncientMagicHotSpot::TrackFootPlants() {
}

void AAncientMagicHotSpot::StopTrackingFootPlants() {
}

void AAncientMagicHotSpot::StartVFX(UNiagaraSystem* InAsset) {
}

void AAncientMagicHotSpot::Reactivate_Implementation() {
}

void AAncientMagicHotSpot::PlayerIsInHotSpot(AActor* InPlayerActor, bool bInHotSpot) {
}


void AAncientMagicHotSpot::LogList(const TArray<AActor*>& LogActorList, const FString& HeaderInfo, const FString& PerActorInfo, const FString& PerActorExtraInfo) const {
}

void AAncientMagicHotSpot::Log(const FString& Info, const UObject* LogObjectName, const FString& ExtraInfo) const {
}

bool AAncientMagicHotSpot::IsHotspotBeingForcedActive() {
    return false;
}

void AAncientMagicHotSpot::Interact_Implementation(UBTService_AvaAITree* AvaService) {
}



void AAncientMagicHotSpot::HideRevealOBJ_Implementation() {
}

void AAncientMagicHotSpot::HideHideOBJ_Implementation() {
}

void AAncientMagicHotSpot::GetLoggingIsEnabled(bool& bLoggingIsEnabled) {
}

void AAncientMagicHotSpot::ForceDeactivateHotSpot() {
}

void AAncientMagicHotSpot::ForceActivateHotSpot(AActor* InPlayerActor, float InRadiiMultiplier, float InHeightMultiplier) {
}


void AAncientMagicHotSpot::FireWand_Implementation() {
}







void AAncientMagicHotSpot::EnableInteract_Implementation() {
}

void AAncientMagicHotSpot::Done(bool NewDeactivateHotSpot) {
}

void AAncientMagicHotSpot::DestroyVFX() {
}



AAncientMagicHotSpot::AAncientMagicHotSpot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bDebugDraw = false;
    this->HotSpotHeightAllowed = 100.00f;
    this->OuterRadiusMaxAngle = 30.00f;
    this->OuterRadiusActiveMaxAngle = 45.00f;
    this->bOuterAngleUseCameraFacing = true;
    this->OuterAngleRatioInterpToSpeed = 3.00f;
    this->OuterAngleRatioInterpOutSpeed = 2.00f;
    this->OuterRadius = 9000.00f;
    this->MinOuterAngleRatio = 0.00f;
    this->MinOuterRadiusRatio = 0.15f;
    this->bInsideOuterRadius = false;
    this->bInsideCollision = false;
    this->InnerRadiusMaxAngle = 45.00f;
    this->bInnerAngleUseCameraFacing = false;
    this->InnerAngleRatioInterpToSpeed = 3.00f;
    this->InnerAngleRatioInterpOutSpeed = 2.00f;
    this->InnerRadius = 1000.00f;
    this->ExitInnerRadius = 1400.00f;
    this->MinInnerAngleRatio = 0.00f;
    this->MinInnerRadiusRatio = 0.15f;
    this->bInsideInnerRadius = false;
    this->HotSpotRadius = 100.00f;
    this->HotSpotRumbleDeadZone = 100.00f;
    this->bInsideHotSpotRadius = false;
    this->bUseDiscoverAbility = false;
    this->bHotSpotActive = false;
    this->bTriggerAOEMunition = false;
    this->NumberOfUses = 1;
    this->Cooldown = 15.00f;
    this->CognitionStimuliSourceComponent = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSourceComponent"));
    this->VFXPulseComponent = NULL;
}

