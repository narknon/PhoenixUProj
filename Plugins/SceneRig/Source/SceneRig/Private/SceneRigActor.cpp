#include "SceneRigActor.h"
#include "Components/SceneComponent.h"

class AActor;
class UPrimitiveComponent;
class USceneRig;
class USceneRigPlayer;

void ASceneRigActor::TriggerEvent(FName EventName) {
}

void ASceneRigActor::StopRepeatedPlay(bool StopCurrentlyPlaying) {
}

void ASceneRigActor::StopImmediate() {
}

void ASceneRigActor::Stop() {
}

USceneRigPlayer* ASceneRigActor::StartRepeatedPlay(float MinRepeatDelay, float MaxRepeatDelay, ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

void ASceneRigActor::ShowSkipUI(bool bShow) {
}

void ASceneRigActor::SetPlaybackScale(float Scale) {
}

void ASceneRigActor::Resume() {
}

bool ASceneRigActor::PlayingOnRepeat() const {
    return false;
}

USceneRigPlayer* ASceneRigActor::PlayImmediate() {
    return NULL;
}

USceneRigPlayer* ASceneRigActor::Play(ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

void ASceneRigActor::Pause() {
}

void ASceneRigActor::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ASceneRigActor::OnCurtainRaised() {
}

void ASceneRigActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool ASceneRigActor::IsSceneRigBeingSkipped(TSoftObjectPtr<USceneRig> NewSceneRig) {
    return false;
}

bool ASceneRigActor::IsPlaying() const {
    return false;
}

bool ASceneRigActor::IsActive() const {
    return false;
}

USceneRigPlayer* ASceneRigActor::Initialize(ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

float ASceneRigActor::GetTimeRemaining() {
    return 0.0f;
}

USceneRigPlayer* ASceneRigActor::GetSceneRigPlayer() const {
    return NULL;
}

USceneRig* ASceneRigActor::GetSceneRig() const {
    return NULL;
}

float ASceneRigActor::GetPlaybackScale() const {
    return 0.0f;
}

USceneRigPlayer* ASceneRigActor::DebugTriggerPlay() {
    return NULL;
}

void ASceneRigActor::AssignSceneRig(USceneRig* InSceneRig) {
}

void ASceneRigActor::AddStartHandler(const FTimeRigEventDynamicDelegate& Handler) {
}

void ASceneRigActor::AddOnCleanupHandler(const FTimeRigEventDynamicDelegate& Handler) {
}

void ASceneRigActor::AddFinishHandler(const FTimeRigEventDynamicDelegate& Handler) {
}

void ASceneRigActor::AddEventHandlerWithActor(FName EventName, FTimeRigEventWithActorDynamicDelegate Delegate) {
}

void ASceneRigActor::AddEventHandler(FName EventName, FTimeRigEventDynamicDelegate Delegate) {
}

ASceneRigActor::ASceneRigActor() {
    this->bAutoInitialize = false;
    this->bAutoPlay = false;
    this->StartTime = 0.00f;
    this->LoadStage = false;
    this->bCreatePreviewActors = false;
    this->LoopIndefinitely = false;
    this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->SceneRig = NULL;
    this->SceneRigProvider = NULL;
    this->StageContainer = NULL;
}

