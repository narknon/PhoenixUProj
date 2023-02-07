#include "FieldGuideHotSpot.h"
#include "CognitionStimuliSourceComponent.h"

class AActor;
class UBTService_AvaAITree;
class UNiagaraSystem;

void AFieldGuideHotSpot::UpdateVFX(float AngleRatio, float DistanceRatio) {
}




void AFieldGuideHotSpot::StartVFX(UNiagaraSystem* InAsset) {
}

void AFieldGuideHotSpot::SetRevealed() {
}


void AFieldGuideHotSpot::PlayerIsInHotSpot(AActor* InPlayerActor, bool bInHotSpot) {
}



void AFieldGuideHotSpot::Log(const FString& InLogString) {
}

bool AFieldGuideHotSpot::IsRevealed() const {
    return false;
}

void AFieldGuideHotSpot::Interact_Implementation(UBTService_AvaAITree* AvaService) {
}






void AFieldGuideHotSpot::DestroyVFX() {
}


void AFieldGuideHotSpot::ClearRevealed() {
}


AFieldGuideHotSpot::AFieldGuideHotSpot() {
    this->bDebugDraw = false;
    this->HotSpotHeightAllowed = 100.00f;
    this->OuterRadius = 9000.00f;
    this->MinOuterRadiusRatio = 0.15f;
    this->bInsideOuterRadius = false;
    this->bInsideCollision = false;
    this->HotSpotRadius = 100.00f;
    this->HotSpotRumbleDeadZone = 100.00f;
    this->bInsideHotSpotRadius = false;
    this->bHotSpotActive = false;
    this->CognitionStimuliSourceComponent = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSourceComponent"));
    this->VFXPulseComponent = NULL;
    this->bPageCollected = false;
}

