#include "MercunaNavOctree.h"
#include "MerNavOctreeRenderingComponent.h"

class AActor;
class AMercunaNavModifierVolume;
class UMercunaPath;
class UMercunaSpline;

void AMercunaNavOctree::UpdateModifierVolumeParams(AMercunaNavModifierVolume* ModifierVolume) {
}

void AMercunaNavOctree::SetNavigationRotation(const FRotator& Rotation) {
}

void AMercunaNavOctree::RemoveModifierVolume(AMercunaNavModifierVolume* ModifierVolume) {
}

void AMercunaNavOctree::RebuildVolumes(const TArray<FBox>& Volumes, bool StagedBuild) {
}

void AMercunaNavOctree::RebuildActorVolume(AActor* Volume, bool StagedBuild) {
}

void AMercunaNavOctree::Raycast(FVector Start, FVector End, float NavigationRadius, FVector& HitPosition, bool& RayHit) {
}

bool AMercunaNavOctree::IsReachableSingle(FVector Start, FVector End, float NavigationRadius, float MaxPathLength) {
    return false;
}

bool AMercunaNavOctree::IsReachable(FVector Start, FVector End, float NavigationRadius, float MaxPathLength, bool AccuratePathLength) {
    return false;
}

void AMercunaNavOctree::IsNavigableMulti(const TArray<FVector>& Positions, float NavigationRadius, TArray<bool>& Results) {
}

void AMercunaNavOctree::IsNavigable(FVector Position, float NavigationRadius, bool& Result) {
}

UMercunaSpline* AMercunaNavOctree::FindSplineToLocation(FVector Start, FVector End, float NavigationRadius, float MaxSpeed, float MaxAcceleration, bool AllowPartial, float MaxPathLength) {
    return NULL;
}

UMercunaPath* AMercunaNavOctree::FindPathToLocation(FVector Start, FVector End, float NavigationRadius, bool AllowPartial, float MaxPathLength) {
    return NULL;
}

UMercunaPath* AMercunaNavOctree::FindPathToActor(FVector Start, AActor* GoalActor, float NavigationRadius, bool AllowPartial, float MaxPathLength) {
    return NULL;
}

void AMercunaNavOctree::ClampToNavigable(FVector Position, float NavigationRadius, float SearchRadius, FVector& ClampedPosition, bool& Result) {
}

void AMercunaNavOctree::CheckReachable(FVector Start, FVector End, float NavigationRadius, float MaxPathLength, bool& Result) {
}

void AMercunaNavOctree::Build() {
}

AMercunaNavOctree::AMercunaNavOctree(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseOverride = false;
    this->SettingsOverride = NULL;
    this->CellSize = 100.00f;
    this->MinPawnRadius = 1;
    this->MaxPawnRadius = 3;
    this->bNeverSave = false;
    this->bAllowOctreeMerging = false;
    this->GeometryCollisionChannel = ECC_Pawn;
    this->bRecordOctreeDeltas = false;
    this->DebugDrawMode = EMerOctreeDebugDrawMode::DISABLED;
    this->MerNavOctreeRenderingComponent = CreateDefaultSubobject<UMerNavOctreeRenderingComponent>(TEXT("MerNavOctreeRenderingComponent"));
    this->bBuildAsSublevel = false;
    this->bNeedsRebuild = false;
}

