#include "SanctuaryStreamingController.h"

class ASanctuaryStreamingController;
class UObject;

void ASanctuaryStreamingController::UnlockLockForZone(FName ZoneName) {
}

void ASanctuaryStreamingController::UnloadZoneExplicitly(FName ZoneName) {
}

void ASanctuaryStreamingController::SetActiveIslandFromZone(FName InZoneName) {
}

void ASanctuaryStreamingController::SetActiveIsland(FName InActiveIsland) {
}

void ASanctuaryStreamingController::RequestZoneReadyToEnter(UObject* WorldContextObject, FName ZoneName, FOnZoneIsReadyCallback OnZoneIsReady, bool bIgnoreLock) {
}

void ASanctuaryStreamingController::RequestZoneLoad(FName ZoneName, bool bMakeVisible, bool bIgnoreLock) {
}

void ASanctuaryStreamingController::OnUpdateStreamingState() {
}

void ASanctuaryStreamingController::MakeZoneVisible(FName ZoneName) {
}

bool ASanctuaryStreamingController::IsZoneUnlocked(FName ZoneName) const {
    return false;
}

bool ASanctuaryStreamingController::IsZoneReadyToEnter(FName ZoneName) const {
    return false;
}

bool ASanctuaryStreamingController::IsZoneMinimumLoadVisible(FName ZoneName) const {
    return false;
}

bool ASanctuaryStreamingController::IsZoneMinimumLoadComplete(FName ZoneName) const {
    return false;
}

bool ASanctuaryStreamingController::IsZoneCompletelyVisible(FName ZoneName) const {
    return false;
}

void ASanctuaryStreamingController::HideParallelLevelsInInactiveIslands() {
}

FName ASanctuaryStreamingController::GetIslandForZone(FName InZoneName) const {
    return NAME_None;
}

ASanctuaryStreamingController* ASanctuaryStreamingController::Get(const UObject* WorldContextObject) {
    return NULL;
}

bool ASanctuaryStreamingController::DoesZoneExist(FName ZoneName) const {
    return false;
}

void ASanctuaryStreamingController::BlockingMinimalZoneLoad(FName ZoneName, bool bMakeVisible) {
}

ASanctuaryStreamingController::ASanctuaryStreamingController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bTreatLightingLevelsAsMinimalLoad = false;
    this->bTeleportLockActive = false;
}

