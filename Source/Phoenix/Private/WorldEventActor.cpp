#include "WorldEventActor.h"
#include "AnimationArchitectComponent.h"

class AActor;
class ABase_Character;
class ANPC_Character;
class AWorldEventLocationActor;
class UAnimationArchitectAsset;
class UChildActorComponent;
class UPrimitiveComponent;
class UScheduledEntity;
class UWorldEventCondition;

bool AWorldEventActor::SetTemporaryAnimationOnCharacter(ANPC_Character* Character, int32 AnimationIndex) {
    return false;
}

bool AWorldEventActor::SetSpecificAnimationOnCharacter(ANPC_Character* Character, UAnimationArchitectAsset* AnimationArchitectAsset) {
    return false;
}

UScheduledEntity* AWorldEventActor::RequestHobo(const FVector& InLocation, const EHoboType HoboType, const TEnumAsByte<HouseIds> InHouse, const EGenderEnum InGender, const TArray<FString>& ValidVoiceIDs) {
    return NULL;
}

UScheduledEntity* AWorldEventActor::RequestCustomHobo(const FString& HoboName, const FVector& InLocation, const bool InIsMale) {
    return NULL;
}

bool AWorldEventActor::RemoveDynamicActivityFromSE(UScheduledEntity* ScheduledEntity, const FString& ActivityID) {
    return false;
}

bool AWorldEventActor::ReleaseTemporaryAnimationFromCharacter(ANPC_Character* Character) {
    return false;
}

void AWorldEventActor::ReleaseHobo(UScheduledEntity* InScheduledEntity, bool InDestroyImmediate) {
}

void AWorldEventActor::ReleaseAllHobos(bool InDestroyImmediate) {
}

void AWorldEventActor::PlayGhostStory(UScheduledEntity* InScheduledEntity, const FName Story, const FName Emotion) {
}



void AWorldEventActor::MarkStageAsIncomplete(int32 Stage) {
}

void AWorldEventActor::MarkStageAsCompleted(int32 Stage) {
}

bool AWorldEventActor::IsStageCompleted(int32 Stage) {
    return false;
}

bool AWorldEventActor::InsertDynamicActivityOnSE(UScheduledEntity* ScheduledEntity, const FString& ActivityID, const FString& LocationID) {
    return false;
}

void AWorldEventActor::HitResult(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

AWorldEventLocationActor* AWorldEventActor::GetWorldEventLocatorActor() {
    return NULL;
}

TArray<FLootSlot> AWorldEventActor::GetRandomLoot(const FString& Category) {
    return TArray<FLootSlot>();
}

int32 AWorldEventActor::GetNumOfWorldEventHobos() {
    return 0;
}

int32 AWorldEventActor::GetNextUncompleteStage() {
    return 0;
}

TEnumAsByte<HouseIds> AWorldEventActor::GetLocationBasedStudentHouse() {
    return HOUSE_GRYFFINDOR;
}

bool AWorldEventActor::FindStudentOnFreeTime(const FVector& InLocation, const float InRadius, const bool InAllowFindHobos, ABase_Character*& OutActor, UScheduledEntity*& OutScheduledEntity) {
    return false;
}

void AWorldEventActor::EnableConversationSense(UScheduledEntity* SE, bool bEnable) {
}

void AWorldEventActor::EnableChildActorComponent(UChildActorComponent* ChildActorComponent) {
}

void AWorldEventActor::EnableCharacter(ABase_Character* Character) {
}

void AWorldEventActor::DisableChildActorComponent(UChildActorComponent* ChildActorComponent) {
}

void AWorldEventActor::DisableCharacter(ABase_Character* Character) {
}

bool AWorldEventActor::CheckCondition(UWorldEventCondition* Conditon) {
    return false;
}

AWorldEventActor::AWorldEventActor() {
    this->AnimationArcitectComponent = CreateDefaultSubobject<UAnimationArchitectComponent>(TEXT("WorldEventAnimationArchitect"));
}

