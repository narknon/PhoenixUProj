#include "BeaconLocation.h"

class AActor;

void ABeaconLocation::SetStartInactive(bool inStartInactive) {
}

void ABeaconLocation::SetShowInWorld(bool inShowInWorld) {
}

void ABeaconLocation::SetParentObject(AActor* inParentObject) {
}

void ABeaconLocation::SetMakeDynamic(bool inMakeDynamic) {
}

void ABeaconLocation::SetIsSaveLocation(bool isSaveLocation) {
}

void ABeaconLocation::SetHudIconSuppressed(bool bInHudIconSuppressed) {
}

void ABeaconLocation::SetHideWhenInactive(bool inHideWhenInactive) {
}

void ABeaconLocation::SetEnterExitDistance(int32 InDistance) {
}

void ABeaconLocation::SetDescriptionShort(const FString& inNewShortDesc) {
}

void ABeaconLocation::SetBeaconType(EBeaconType inBeaconType) {
}

void ABeaconLocation::SetBeaconPriority(EBeaconDisplayPriority InPriority) {
}

void ABeaconLocation::SetBeaconName(const FString& inNewBeaconName) {
}

void ABeaconLocation::SetBeaconDebug(bool inDoDebug) {
}

void ABeaconLocation::SetBeaconableObjectID(FName inNewID) {
}

void ABeaconLocation::SetActivationDistance(int32 InDistance) {
}

bool ABeaconLocation::GetStartInactive() {
    return false;
}

bool ABeaconLocation::GetShowInWorld() {
    return false;
}

bool ABeaconLocation::GetMakeDynamic() {
    return false;
}

bool ABeaconLocation::GetIsSaveLocation() {
    return false;
}

bool ABeaconLocation::GetHideWhenInactive() {
    return false;
}

int32 ABeaconLocation::GetEnterExitDistance() {
    return 0;
}

bool ABeaconLocation::GetDrawDebug() {
    return false;
}

FString ABeaconLocation::GetDescriptionShort() {
    return TEXT("");
}

EBeaconType ABeaconLocation::GetBeaconType() {
    return EBeaconType::BEACONTYPE_NONE;
}

EBeaconDisplayPriority ABeaconLocation::GetBeaconPriority() {
    return EBeaconDisplayPriority::BEACON_DISPLAY_PRIORITY_LOW;
}

FString ABeaconLocation::GetBeaconName() {
    return TEXT("");
}

FString ABeaconLocation::GetBeaconID() {
    return TEXT("");
}

FDbSingleColumnInfo ABeaconLocation::GetBeaconIcon() {
    return FDbSingleColumnInfo{};
}

int32 ABeaconLocation::GetBeaconHandle() {
    return 0;
}

FName ABeaconLocation::GetBeaconableObjectID() {
    return NAME_None;
}

int32 ABeaconLocation::GetActivationDistance() {
    return 0;
}

ABeaconLocation::ABeaconLocation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BeaconType = EBeaconType::BEACONTYPE_LOCATIONS;
    this->ActivationDistance = 0;
    this->EnterExitDistance = 0;
    this->BeaconPriority = EBeaconDisplayPriority::BEACON_DISPLAY_PRIORITY_LOW;
    this->bMakeDynamic = false;
    this->bHideWhenInactive = false;
    this->bShowInWorld = false;
    this->bStartInactive = false;
    this->bIsSaveLocation = false;
    this->bDrawDebug = false;
}

