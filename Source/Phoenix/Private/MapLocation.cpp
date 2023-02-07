#include "MapLocation.h"

class AMapLocationActor;
class UMapLocation;
class UMapMarkupComponent;

void UMapLocation::SetParent(UMapLocation* ParentIn) {
}

void UMapLocation::SetIsPrimary(bool IsPrimaryIn) {
}

UMapLocation* UMapLocation::RemoveLocation(UMapLocation* LocationIn) {
    return NULL;
}

bool UMapLocation::IsRoot() {
    return false;
}

bool UMapLocation::IsPrimary() {
    return false;
}

float UMapLocation::GetVolume() {
    return 0.0f;
}

FRotator UMapLocation::GetRotation() {
    return FRotator{};
}

UMapLocation* UMapLocation::GetPrimaryInTree() {
    return NULL;
}

UMapLocation* UMapLocation::GetParent() {
    return NULL;
}

UMapMarkupComponent* UMapLocation::GetMapMarkupComponent() {
    return NULL;
}

FString UMapLocation::GetLocationId() {
    return TEXT("");
}

UMapLocation* UMapLocation::GetLocationByName(const FString& LocationName) {
    return NULL;
}

AMapLocationActor* UMapLocation::GetLocationActor() {
    return NULL;
}

FVector UMapLocation::GetLocation() {
    return FVector{};
}

FVector UMapLocation::GetExtent() {
    return FVector{};
}

TArray<UMapLocation*> UMapLocation::GetChildren() {
    return TArray<UMapLocation*>();
}

FVector UMapLocation::GetCenter() {
    return FVector{};
}

int32 UMapLocation::Depth() {
    return 0;
}

UMapLocation* UMapLocation::CreateLocationUsingComponent(const FString& RegionIn, AMapLocationActor* LocationActorIn, FMarkupData MarkupDataIn) {
    return NULL;
}

UMapLocation* UMapLocation::CreateLocation(const FString& RegionIn, const FString& LocationIdIn, FVector LocationIn, FVector ExtentIn, FRotator RotationIn, FMarkupData MarkupDataIn) {
    return NULL;
}

bool UMapLocation::ContainsPoint(FVector Point) {
    return false;
}

bool UMapLocation::ContainsLocation(const FString& LocationIdIn) {
    return false;
}

bool UMapLocation::AddLocation(UMapLocation* MapLocation) {
    return false;
}

UMapLocation::UMapLocation() {
    this->locationActor = NULL;
    this->MapMarkupComponent = NULL;
}

