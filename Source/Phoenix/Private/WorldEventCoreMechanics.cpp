#include "WorldEventCoreMechanics.h"

class AActor;
class AWorldEventLocationActor;

void AWorldEventCoreMechanics::ToggleMaskValue(EProductionStatus Status) {
}

TArray<FName> AWorldEventCoreMechanics::SortAlphabetically(TArray<FName> unsortedArray) {
    return TArray<FName>();
}

void AWorldEventCoreMechanics::SetTag(FGameplayTag Tag) {
}

bool AWorldEventCoreMechanics::RowMatchesProductionFilter(const FWorldEventDataRow& Row) {
    return false;
}

void AWorldEventCoreMechanics::OnWorldEventLoaded(AWorldEventLocationActor* Location, const FWorldEventDataRow& Row) {
}

void AWorldEventCoreMechanics::OnPreviewLevelLoaded() {
}

void AWorldEventCoreMechanics::OnPlayerReturned() {
}

bool AWorldEventCoreMechanics::MaskMatchesFilter(EProductionStatus Status) {
    return false;
}

void AWorldEventCoreMechanics::LoadAndTeleport(FName weName) {
}

void AWorldEventCoreMechanics::GetPositionAndRotation(int32 Index, int32 Count, const AActor* StartLocation, int32 rowLength, FVector axisAlignment, FVector& OutPosition, FRotator& OutRotation, int32 Width) {
}

TArray<FGameplayTag> AWorldEventCoreMechanics::GetLocationTags() {
    return TArray<FGameplayTag>();
}

AWorldEventCoreMechanics::AWorldEventCoreMechanics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GeneralLocationActor = NULL;
    this->TeleportLocationActor = NULL;
    this->ProductionStatusMask = 0;
}

