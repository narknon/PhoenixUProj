#include "ForbiddenAreaVolume.h"
#include "Components/BoxComponent.h"

class AActor;

void AForbiddenAreaVolume::SetActive(bool bActive) {
}

void AForbiddenAreaVolume::OnEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void AForbiddenAreaVolume::OnBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void AForbiddenAreaVolume::Deactivate() {
}

void AForbiddenAreaVolume::Activate() {
}

AForbiddenAreaVolume::AForbiddenAreaVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
    this->bIsActive = true;
    this->bDisableCompanion = false;
    this->FilterSetting = EForbiddenAreaSetting::All;
}

