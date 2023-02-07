#include "Door.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "OdcObstacleComponent.h"
#include "DoorBoxComponent.h"

class AActor;
class UObject;
class UPrimitiveComponent;

void ADoor::SwingDoorFinished() {
}

void ADoor::SetState(EDoorState DoorState, bool LockVisible, bool PlaySoundsAndEffects) {
}

void ADoor::SetLockLevel(const UObject* Caller, int32 Int) {
}

void ADoor::SetKeepDoorOpen(bool InKeepDoorOpen) {
}

void ADoor::RotateDoorToAlpha(float Alpha) {
}

void ADoor::OpenDoor(bool KeepOpen, float SecondsToDelayClosing, bool bPushedOpen, EOpenDoorDirection Direction) {
}

void ADoor::OnEnterTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* ActorInTrigger, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ADoor::ObjectPickedUp(UObject* Caller) {
}

void ADoor::DestroyWidgetComponentSpinner() {
}

void ADoor::CloseDoor(bool ForceClose) {
}

void ADoor::BlockPlayer(bool ShouldBlock) {
}

void ADoor::BlockOrUnblockDoor() {
}

void ADoor::BlockNavMesh(bool ShouldBlock, EBlockNavMeshOverride Override) {
}

ADoor::ADoor() {
    this->EnvInt = 0;
    this->PropIndex = 0;
    this->UseDoorFrame = true;
    this->ChildDoor = NULL;
    this->RegisterNamedDoor = false;
    this->Open = false;
    this->KeepDoorOpen = false;
    this->DefaultOpenDoorForward = true;
    this->TimeToOpenDoor = 1.00f;
    this->TimeToKeepDoorOpen = 1.00f;
    this->TimeToHoldDoorWhenInVolume = 5.00f;
    this->TimeToCloseDoor = 1.00f;
    this->BaseCharacterSpeed = 250.00f;
    this->BaseHingeDistanceRatio = 0.90f;
    this->MinOpenSpeedMultiplier = 0.75f;
    this->MaxOpenSpeedMultiplier = 3.00f;
    this->MinDoorAngle = -90.00f;
    this->MaxDoorAngle = 90.00f;
    this->AllowNPCToPassThroughLockedDoor = true;
    this->BlockNPCsIfLocked = false;
    this->SlowPlayerInFrontOfDoor = true;
    this->ExpiryTime = 259200;
    this->ForceTickEnabled = false;
    this->bNeverBlockNavGuide = false;
    this->AcousticPortal = NULL;
    this->RenderSettingsCustomBlendDomainVolumeAttached = NULL;
    this->LerpVolumeAttached = NULL;
    this->OpeningSound = NULL;
    this->OpenedSound = NULL;
    this->ClosingSound = NULL;
    this->ClosedSound = NULL;
    this->BellSound = NULL;
    this->FrontCaresAboutStreaming = false;
    this->BackCaresAboutStreaming = false;
    this->FrontIsExterior = false;
    this->BackIsExterior = false;
    this->OpenCurve = NULL;
    this->CloseCurve = NULL;
    this->CloseDoorCurveAdjustment = EDoorCurveAdjustment::Reverse;
    this->DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
    this->FrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrameMesh"));
    this->NavObstacle = CreateDefaultSubobject<UOdcObstacleComponent>(TEXT("NavObstacle"));
    this->ForwardArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ForwardArrow"));
    this->ClosedDoorNavObstacle = CreateDefaultSubobject<UOdcObstacleComponent>(TEXT("PermanentNavObstacle"));
    this->EnterTrigger = CreateDefaultSubobject<UDoorBoxComponent>(TEXT("EnterTriggerBox"));
    this->ExitTrigger = CreateDefaultSubobject<UDoorBoxComponent>(TEXT("ExitTriggerBox"));
    this->PlayerCollision = CreateDefaultSubobject<UDoorBoxComponent>(TEXT("Collision"));
    this->WidgetComponentSpinner = NULL;
    this->FastTravelComponent = NULL;
}

