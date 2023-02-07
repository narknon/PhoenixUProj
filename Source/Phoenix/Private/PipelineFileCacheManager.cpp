#include "PipelineFileCacheManager.h"

class UPipelineFileCacheManager;

void UPipelineFileCacheManager::ResumeBatching() {
}

void UPipelineFileCacheManager::PauseBatching() {
}

bool UPipelineFileCacheManager::IsPrecachingEnabled() {
    return false;
}

bool UPipelineFileCacheManager::IsPipelioneFileCacheManagerEnabled() {
    return false;
}

bool UPipelineFileCacheManager::IsBatchingPaused() {
    return false;
}

UPipelineFileCacheManager* UPipelineFileCacheManager::Get() {
    return NULL;
}

UPipelineFileCacheManager::UPipelineFileCacheManager() {
}

