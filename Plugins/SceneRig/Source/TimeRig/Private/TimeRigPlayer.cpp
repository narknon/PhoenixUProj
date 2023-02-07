#include "TimeRigPlayer.h"

class UTimeRig;

void UTimeRigPlayer::StopIn(float SecondsFromNow, float BlendTime) {
}

void UTimeRigPlayer::StopImmediate() {
}

void UTimeRigPlayer::Stop() {
}

bool UTimeRigPlayer::Skip() {
    return false;
}

void UTimeRigPlayer::SetTime(float Seconds) {
}

void UTimeRigPlayer::SetSecondsRemainingForAlmostCompleteTrigger(float Seconds) {
}

void UTimeRigPlayer::SetRoundTimeToFPS(float FPS) {
}

void UTimeRigPlayer::SetPlaybackScale(float Scale) {
}

bool UTimeRigPlayer::SetOnPlaybackStarting(FTimeRigOnPlaybackStarting InOnPlaybackStarting) {
    return false;
}

bool UTimeRigPlayer::SetOnPlaybackStarted(FTimeRigOnPlaybackStartedDynamic InOnPlaybackStarted) {
    return false;
}

bool UTimeRigPlayer::SetLooping(bool LoopingEnabled) {
    return false;
}

void UTimeRigPlayer::RewindToCurrentStartOf(UClass* ActionType) {
}

bool UTimeRigPlayer::ReadyToPlay() const {
    return false;
}

bool UTimeRigPlayer::PlayImmediate(FName InActivationSource) {
    return false;
}

bool UTimeRigPlayer::PlaybackHasStarted() const {
    return false;
}

bool UTimeRigPlayer::Play(FName InActivationSource) {
    return false;
}

void UTimeRigPlayer::PauseAfterCurrentEndOf(UClass* ActionType) {
}

void UTimeRigPlayer::Pause() {
}

bool UTimeRigPlayer::IsWantingToPlayButNotPlaying() const {
    return false;
}

bool UTimeRigPlayer::IsTicking() const {
    return false;
}

bool UTimeRigPlayer::IsStopping() const {
    return false;
}

bool UTimeRigPlayer::IsPlaying() const {
    return false;
}

bool UTimeRigPlayer::IsLooping() const {
    return false;
}

bool UTimeRigPlayer::IsInitializing() const {
    return false;
}

bool UTimeRigPlayer::IsInitialized() const {
    return false;
}

bool UTimeRigPlayer::IsActive() const {
    return false;
}

bool UTimeRigPlayer::HasEvent(FName EventName) {
    return false;
}

UTimeRig* UTimeRigPlayer::GetTimeRig() const {
    return NULL;
}

float UTimeRigPlayer::GetTime() const {
    return 0.0f;
}

float UTimeRigPlayer::GetSecondsRemainingForAlmostCompleteTrigger() const {
    return 0.0f;
}

float UTimeRigPlayer::GetRoundTimeToFPS() const {
    return 0.0f;
}

ETimeRigPlayerState UTimeRigPlayer::GetPlayerState() const {
    return ETimeRigPlayerState::Uninitialized;
}

float UTimeRigPlayer::GetPlaybackScale() const {
    return 0.0f;
}

float UTimeRigPlayer::GetEndTime() const {
    return 0.0f;
}

float UTimeRigPlayer::GetCurrentTime() const {
    return 0.0f;
}

float UTimeRigPlayer::GetBeginTime() const {
    return 0.0f;
}

void UTimeRigPlayer::FastForwardToNextStartOf(UClass* ActionType) {
}

void UTimeRigPlayer::FastForwardToNextEndOf(UClass* ActionType) {
}

void UTimeRigPlayer::FastForwardToEvent(const FName& EventName) {
}

void UTimeRigPlayer::FastForwardToCurrentEndOf(UClass* ActionType) {
}

bool UTimeRigPlayer::EventOccursNow(FName EventName) {
    return false;
}

bool UTimeRigPlayer::EventOccursAt(FName EventName, float SecondsFromNow) {
    return false;
}

bool UTimeRigPlayer::AddEventHandler(FName EventName, const FTimeRigEventDynamicDelegate& Handler) {
    return false;
}

bool UTimeRigPlayer::AddCriticalEventHandler(FName EventName, const FTimeRigCriticalEventDynamicDelegate& Handler) {
    return false;
}

UTimeRigPlayer::UTimeRigPlayer() {
    this->TimeRig = NULL;
    this->InstanceContext = NULL;
    this->PlaybackScale = 1.00f;
    this->RoundTimeToFPS = 0.00f;
    this->SecondsRemainingForAlmostCompleteTrigger = 3.00f;
}

