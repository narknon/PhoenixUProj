#include "PhoenixHoverDronePawn.h"
#include "Components/CapsuleComponent.h"

class AActor;
class UPrimitiveComponent;

bool APhoenixHoverDronePawn::IsMaintainingConstantAltitude() const {
    return false;
}

float APhoenixHoverDronePawn::GetAltitude() const {
    return 0.0f;
}

void APhoenixHoverDronePawn::AllowIcons(bool InVal) {
}

void APhoenixHoverDronePawn::ActorOverlapEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void APhoenixHoverDronePawn::ActorOverlapBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& OverlapInfo) {
}

APhoenixHoverDronePawn::APhoenixHoverDronePawn() {
    this->MaxAccelToGravRatio = 0.20f;
    this->DroneTiltInterpSpeed_Accel = 1.00f;
    this->DroneTiltInterpSpeed_Decel = 2.00f;
    this->ZoomRate = 30.00f;
    this->FOVInterpSpeed = 7.00f;
    this->maxFOV = 160.00f;
    this->minFOV = 5.00f;
    this->SpeedAdjustment = 1.00f;
    this->SpeedAdjustRate = 0.10f;
    this->SpeedAdjustMin = 0.10f;
    this->SpeedAdjustMax = 3.00f;
    this->MinIconScale = 0.20f;
    this->MinIconDist = 500.00f;
    this->MaxIconDist = 10000.00f;
    this->bAutoFocus = true;
    this->AutoFocusInterpSpeed = 12.00f;
    this->CameraApertureFStop = 4.00f;
    this->ScreenFringeFOVCurve = NULL;
    this->m_progressWidgetClass = NULL;
    this->m_followWidgetClass = NULL;
    this->m_filterComponentClass = NULL;
    this->m_MinimapWidgetClass = NULL;
    this->FoliageOverlapComponent = NULL;
    this->ActorOverlapComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("ActorOverlapCapsule0"));
    this->m_pMinimapWidget = NULL;
    this->m_pProgressWidget = NULL;
    this->m_pFollowWidget = NULL;
}

