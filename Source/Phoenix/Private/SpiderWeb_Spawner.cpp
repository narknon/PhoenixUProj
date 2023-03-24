#include "SpiderWeb_Spawner.h"

class AActor;
class ADynamicObjectVolume;
class UPrimitiveComponent;
class UStaticMeshComponent;

bool ASpiderWeb_Spawner::WebThaw() {
    return false;
}

void ASpiderWeb_Spawner::WebHit() {
}

void ASpiderWeb_Spawner::WebFreeze() {
}

void ASpiderWeb_Spawner::WebBurn() {
}

void ASpiderWeb_Spawner::SpawnSpiders() {
}

void ASpiderWeb_Spawner::SetSpawner(ADynamicObjectVolume* newSpawner) {
}

bool ASpiderWeb_Spawner::OnSpawnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
    return false;
}

bool ASpiderWeb_Spawner::OnSpawnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
    return false;
}

bool ASpiderWeb_Spawner::IsSpider(AActor* checkActor) {
    return false;
}

FTransform ASpiderWeb_Spawner::GetRelativeTransform(UStaticMeshComponent* StaticMesh, FVector FireLocation) {
    return FTransform{};
}

ASpiderWeb_Spawner::ASpiderWeb_Spawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnerVolume = NULL;
    this->SpawnTime = 5.00f;
    this->bDestroyOnSpawn = true;
    this->bIgnoreType = true;
    this->IgnoreTypeName = TEXT("spider");
    this->bBurning = false;
    this->bFrozen = false;
    this->SpawnNum = 0;
}

