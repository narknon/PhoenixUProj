#include "AvaStreamingManager.h"

class AActor;
class APostProcessVolumeWithBlendDomain;
class UAvaStreamingManager;
class ULevelStreaming;
class UMaterialInterface;
class UObject;

void UAvaStreamingManager::UpdateOverlaps() {
}

bool UAvaStreamingManager::UnregisterInterestPointActor(AActor* InActor) {
    return false;
}

void UAvaStreamingManager::UnloadLevelInstance(ULevelStreaming* InLevel) {
}

void UAvaStreamingManager::UnloadAllButCurrentLevel() {
}

void UAvaStreamingManager::SuppressPauseStreamingAutoReset(bool bSuppress) {
}

void UAvaStreamingManager::SetStreamingBehaviorMode(EStreamingBehaviorMode BehaviorMode) {
}

void UAvaStreamingManager::SetLowEndFog(APostProcessVolumeWithBlendDomain* LowEndFog, UMaterialInterface* LowEndFogMaterialBase) {
}

void UAvaStreamingManager::ResumeStreaming(bool bForceImmediate, bool bResumeTileStreaming) {
}

bool UAvaStreamingManager::RegisterInterestPointActor(AActor* InActor, float InAdditionalRadius, bool InAffectsInteriors, bool InAffectsTileRegionVolumes) {
    return false;
}

void UAvaStreamingManager::PreventInteriorLoads(bool bPrevent) {
}

void UAvaStreamingManager::PauseStreaming(bool bWorldTilesOnly) {
}

void UAvaStreamingManager::OnLoadScreenDismissed() {
}

void UAvaStreamingManager::LowerCurtainUntilStreamingComplete() {
}

void UAvaStreamingManager::LoadGlobalLevels() {
}

bool UAvaStreamingManager::IsTileRenderingEnabled() {
    return false;
}

bool UAvaStreamingManager::IsStreamingPaused() {
    return false;
}

bool UAvaStreamingManager::IsStreamingCompleteFullCycle(bool bCheckOnlyLOD0, bool bUseDelay) {
    return false;
}

bool UAvaStreamingManager::IsStreamingCompleteAtLocationFullCycle(const FVector& InQueryPoint, bool InQueryWorldTiles, bool InUseSlowAccurateCheck, bool InConsiderFutureRequestAtLocation) {
    return false;
}

bool UAvaStreamingManager::IsStreamingCompleteAtLocation(const FVector& InQueryPoint, bool InQueryWorldTiles, bool InUseSlowAccurateCheck, bool InConsiderFutureRequestAtLocation, int32 MinPriorityToCheck, bool bCheckTextureAndMeshStreaming) {
    return false;
}

bool UAvaStreamingManager::IsStreamingComplete(bool bCheckOnlyLOD0, bool bUseDelay, bool bConsiderUpdatePending, bool bConsiderUnloads) {
    return false;
}

void UAvaStreamingManager::InvalidateStreamingComplete(bool InRequireFullUpdates) {
}

EStreamingBehaviorTactic UAvaStreamingManager::GetStreamingBehaviorTactic() const {
    return EStreamingBehaviorTactic::Balanced;
}

EStreamingBehaviorMode UAvaStreamingManager::GetStreamingBehaviorMode() const {
    return EStreamingBehaviorMode::Loading;
}

UAvaStreamingManager* UAvaStreamingManager::GetPure() {
    return NULL;
}

UAvaStreamingManager* UAvaStreamingManager::Get() {
    return NULL;
}

void UAvaStreamingManager::FlushStreaming() {
}

void UAvaStreamingManager::AsyncLoadAssetList(const UObject* WorldContextObject, const TArray<TSoftObjectPtr<UObject>>& AssetsToStream, int32& UniqueId) {
}

UAvaStreamingManager::UAvaStreamingManager() {
    this->LevelStreamingLatencyProfiler = NULL;
    this->LowEndFogCullingVolume = NULL;
    this->LowEndFogCullingMaterialInstanceDynamic = NULL;
}

