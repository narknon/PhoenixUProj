#include "Creature_GroupCoordinator.h"

class AActor;

void UCreature_GroupCoordinator::SetTagLimitOnActor(AActor* Subject, FName Identifier, int32 Limit) {
}

bool UCreature_GroupCoordinator::RemoveTagsWithIDFromActor(AActor* Subject, FName Identifier) {
    return false;
}

void UCreature_GroupCoordinator::RemoveTagLimitOnActor(AActor* Subject, FName Identifier) {
}

void UCreature_GroupCoordinator::RemoveAllLocationTagsWithIDAndOwner(FName Identifier, AActor* Owner) {
}

void UCreature_GroupCoordinator::RemoveAllActorTagsWithIDAndOwner(FName Identifier, AActor* Owner) {
}

bool UCreature_GroupCoordinator::RemoveActorTag(AActor* Subject, FName Identifier, AActor* Owner) {
    return false;
}

void UCreature_GroupCoordinator::RegisterLocationTag(FVector Location, FName Identifier, float Radius, float LifeTime, AActor* Owner) {
}

bool UCreature_GroupCoordinator::RegisterActorTag(AActor* Subject, FName Identifier, float LifeTime, AActor* Owner) {
    return false;
}

int32 UCreature_GroupCoordinator::GetTagLimitOnActor(AActor* Subject, FName Identifier) {
    return 0;
}

bool UCreature_GroupCoordinator::GetDoesLocationTagExistIgnoreOwner(FVector Location, FName Identifier, float SearchRadius, AActor* OwnerToIgnore) {
    return false;
}

bool UCreature_GroupCoordinator::GetDoesLocationTagExistFromOwner(FVector Location, FName Identifier, float SearchRadius, AActor* Owner) {
    return false;
}

bool UCreature_GroupCoordinator::GetDoesLocationTagExist(FVector Location, FName Identifier, float SearchRadius) {
    return false;
}

bool UCreature_GroupCoordinator::GetDoesActorTagExistIgnoreOwner(const AActor* Subject, FName Identifier, AActor* OwnerToIgnore) {
    return false;
}

bool UCreature_GroupCoordinator::GetDoesActorTagExistFromOwner(const AActor* Subject, FName Identifier, AActor* Owner) {
    return false;
}

bool UCreature_GroupCoordinator::GetDoesActorTagExist(const AActor* Subject, FName Identifier) {
    return false;
}

TArray<FCreature_GroupCoordination_LocationTag> UCreature_GroupCoordinator::GetAllOverlappingLocationTags(FVector Location, FName Identifier, float SearchRadius) {
    return TArray<FCreature_GroupCoordination_LocationTag>();
}

bool UCreature_GroupCoordinator::GetActorTagLifetimeLeftFromOwner(const AActor* Subject, FName Identifier, AActor* Owner, float& OutTagAge) {
    return false;
}

bool UCreature_GroupCoordinator::GetActorTagAgeFromOwner(const AActor* Subject, FName Identifier, AActor* Owner, float& OutTagAge) {
    return false;
}

UCreature_GroupCoordinator::UCreature_GroupCoordinator() {
}

