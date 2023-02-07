#include "TutorialSystem.h"

class UObject;
class UPhoenixUserWidget;
class UTutorialSystem;

void UTutorialSystem::ZoomLowerHogsfield(const UObject* sender) {
}

void UTutorialSystem::UnpauseTutorialQueue(const FString& Context) {
}

bool UTutorialSystem::TutorialsAvailable() {
    return false;
}

void UTutorialSystem::StopCallAttentionToAnnex(const UObject* sender) {
}

bool UTutorialSystem::StartTutorialStepExpiryTimerByAlias(const FName TutorialName, const FName TutorialStepAlias) {
    return false;
}

bool UTutorialSystem::StartTutorialStepExpiryTimer(const FName TutorialName, const int32 TutorialStep) {
    return false;
}

bool UTutorialSystem::StartTutorial(const FName TutorialName, const bool AfterNotifications) {
    return false;
}

void UTutorialSystem::StartNextTutorial() {
}

void UTutorialSystem::SetZZDActivate(const UObject* sender) {
}

void UTutorialSystem::SetupMapTutorials(const UObject* sender) {
}

void UTutorialSystem::SetupMapIconsForOverlandTutorial(const UObject* sender) {
}

void UTutorialSystem::SetupMapFastTravelTutorial(const UObject* sender) {
}

void UTutorialSystem::ResetMapFastTravelTutorial(const UObject* sender) {
}

void UTutorialSystem::ResetMap(const UObject* sender) {
}

void UTutorialSystem::PauseTutorialQueue(const FString& Context) {
}

void UTutorialSystem::OverlandZoomOut(const UObject* sender) {
}

void UTutorialSystem::OverlandZoomIn(const UObject* sender) {
}

void UTutorialSystem::OnSaveGameLoaded() {
}

void UTutorialSystem::OnMissionFailedScreenLoaded(const UObject* sender) {
}

void UTutorialSystem::OnIntroEnded(UPhoenixUserWidget* PhoenixWidget, int32 OutroType) {
}

void UTutorialSystem::OnGameToBeSaved() {
}

void UTutorialSystem::OnCurrentScreenOutroEnded(UPhoenixUserWidget* PhoenixWidget, int32 OutroType) {
}

bool UTutorialSystem::IsTutorialStepActiveOrAboutToBeByAlias(const FName TutorialName, const FName TutorialStepAlias) const {
    return false;
}

bool UTutorialSystem::IsTutorialStepActiveOrAboutToBe(const FName TutorialName, const int32 TutorialStep) const {
    return false;
}

bool UTutorialSystem::IsTutorialStepActiveByAlias(const FName TutorialName, const FName TutorialStepAlias) const {
    return false;
}

bool UTutorialSystem::IsTutorialStepActive(const FName TutorialName, const int32 TutorialStep) const {
    return false;
}

bool UTutorialSystem::IsTutorialQueuePaused() const {
    return false;
}

bool UTutorialSystem::IsTutorialQueued(const FName TutorialName) const {
    return false;
}

bool UTutorialSystem::IsTutorialActiveOrAboutToBe(const FName TutorialName) const {
    return false;
}

bool UTutorialSystem::IsTutorialActive(const FName TutorialName) const {
    return false;
}

bool UTutorialSystem::IsModalTutorialQueued() const {
    return false;
}

bool UTutorialSystem::IsCurrentTutorialActive() const {
    return false;
}

bool UTutorialSystem::IsAnyTutorialQueued() const {
    return false;
}

void UTutorialSystem::HighlightCharmsClass(const UObject* sender) {
}

void UTutorialSystem::HideLivingQuarters(const UObject* sender) {
}

void UTutorialSystem::HermesStartNextTutorial() {
}

bool UTutorialSystem::GetInitialTutorialStepInProgress() {
    return false;
}

UTutorialSystem* UTutorialSystem::Get() {
    return NULL;
}

bool UTutorialSystem::ForceCompleteTutorial(const FName TutorialName, bool DontFireCompletionMessages) {
    return false;
}

void UTutorialSystem::CompleteTutorialStepInternal() {
}

bool UTutorialSystem::CompleteTutorialStepByAlias(const FName TutorialName, const FName TutorialStepAlias) {
    return false;
}

bool UTutorialSystem::CompleteTutorialStep(const FName TutorialName, const int32 TutorialStep) {
    return false;
}

bool UTutorialSystem::CompleteTutorialCurrentStep(const FName TutorialName) {
    return false;
}

void UTutorialSystem::ClosePauseMenu(const UObject* sender) {
}

void UTutorialSystem::CallAttentionToAnnex(const UObject* sender) {
}

void UTutorialSystem::BackOutOfRegion(const UObject* sender) {
}

void UTutorialSystem::AllowTravelToAnnex(const UObject* sender) {
}

bool UTutorialSystem::AbortTutorial(const FName TutorialName, const bool bInstant) {
    return false;
}

void UTutorialSystem::AbortQueuedTutorials(const UObject* sender) {
}

UTutorialSystem::UTutorialSystem() {
    this->CurrentTutorialScreen = NULL;
}

