#include "MunitionType_PhoenixSubsonic.h"

class AActor;
class ASpellTool;
class UPrimitiveComponent;

ASpellTool* AMunitionType_PhoenixSubsonic::GetSpellTool() const {
    return NULL;
}

void AMunitionType_PhoenixSubsonic::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

AMunitionType_PhoenixSubsonic::AMunitionType_PhoenixSubsonic(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanOppugnoAfterProtego = false;
    this->OppugnoPhysicsObjectClass = NULL;
    this->SpellTool = NULL;
}

