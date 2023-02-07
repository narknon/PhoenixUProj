#include "BroomRiderSpawner.h"
#include "Templates/SubclassOf.h"

class AActor;
class AFlyingBroom;

bool ABroomRiderSpawner::RequestBroomNPC(const EHoboType HoboType, const TEnumAsByte<HouseIds> InHouse, const EGenderEnum InGender, const TArray<FString>& ValidVoiceIDs, TSubclassOf<AFlyingBroom> FlyingBroom, TEnumAsByte<EBroomEnemyState::Type> StudentAISpawnState, float MaxSpeed) {
    return false;
}

void ABroomRiderSpawner::OnFleshLoadComplete(AActor* ScheduledEntityActor) {
}

void ABroomRiderSpawner::DestroyAllRiders_Implementation() {
}

ABroomRiderSpawner::ABroomRiderSpawner() {
    this->BroomSpline = NULL;
    this->FlyingBroomPhysics = NULL;
}

