#include "LODViewerManager.h"

class UPhoenixSignificanceManager;
class USkeletalMesh;
class USkeletalMeshComponent;

TArray<FString> ULODViewerManager::PopulateListOfSkeletalMeshes() {
    return TArray<FString>();
}

int32 ULODViewerManager::GetSkeletalMeshPredictedLODLevel(USkeletalMeshComponent* SkeletalMeshComponent) {
    return 0;
}

FName ULODViewerManager::GetObjectPathByString(const FString& AssetName) {
    return NAME_None;
}

int32 ULODViewerManager::GetNumLODsForViewer(USkeletalMesh* SkeletalMesh) {
    return 0;
}

TArray<FLODViewerInfos> ULODViewerManager::GetLODInfoFromSkeletalMesh(USkeletalMesh* SkeletalMesh) {
    return TArray<FLODViewerInfos>();
}

float ULODViewerManager::ComputeScreenRadius(const FVector& Origin, const float Radius, const FVector& ViewOrigin, UPhoenixSignificanceManager* SigManager) {
    return 0.0f;
}

float ULODViewerManager::ComputePixelsOnScreen(float ScreenDiameter, float ResolutionMax) {
    return 0.0f;
}

TArray<float> ULODViewerManager::CalculateLODDistancesFromSphereRadius(TArray<float> LODScreenSizes, float Radius, UPhoenixSignificanceManager* SigManager) {
    return TArray<float>();
}

ULODViewerManager::ULODViewerManager() {
}

